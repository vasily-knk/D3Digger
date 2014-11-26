#pragma once

namespace bytes
{

typedef vector<char> bytes_t;
typedef shared_ptr<bytes_t> bytes_ptr;
typedef shared_ptr<const bytes_t> bytes_const_ptr;
typedef int32_t size_type;

inline bytes_ptr make()
{
    return make_shared<bytes_t>();
}

namespace inner
{

    inline void reserve_additional(bytes_ptr bytes, size_t size)
    {
        bytes->reserve(bytes->size() + size);
    }

    inline bytes_ptr make(size_t size)
    {                                             
        return make_shared<bytes_t>(size);
    }

    template<typename T>
    void put(const T &data, bytes_ptr bytes, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
    {
        const size_t offset = bytes->size();
        bytes->resize(offset + sizeof(T));
        *reinterpret_cast<T*>(&bytes->at(offset)) = data;
    }

    template<typename T>
    void put_array(T const *p, size_t num, bytes_ptr bytes, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
    {
        size_t offset = bytes->size();
        size_t size = num * sizeof(T);
        bytes->resize(offset + size);
        memcpy(&bytes->at(offset), p, size);
    }

    inline void append(bytes_ptr dst, bytes_const_ptr src)
    {
        reserve_additional(dst, src->size());
        std::copy(src->begin(), src->end(), std::back_inserter(*dst));
    }

    struct getter
    {
        struct error 
            : std::runtime_error
        {
            error(string message)
                : std::runtime_error(message)
            {

            }
        };
    
        getter(bytes_ptr bytes, bool allowLeft = false)
            : bytes_(bytes)
            , offset_(0)
            , allowLeft_(allowLeft)
        { }

        ~getter()
        {
            Assert(allowLeft_ || left() == 0);
        }

        size_t left() const 
        {
            Assert(offset_ <= bytes_->size());
            return bytes_->size() - offset_;
        }
    
        template<typename T>
        void get(T &data, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
        {
            if (offset_ + sizeof(T) > bytes_->size())
                throw error("Not enough bytes");
            data = *reinterpret_cast<T*>(&bytes_->at(offset_));
            offset_ += sizeof(T);
        }

        template<typename T>
        void get_array(T *p, size_t num, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
        {
            size_t size = sizeof(T) * num;
            if (offset_ + size > bytes_->size())
                throw error("Not enough bytes");

            memcpy(p, &bytes_->at(offset_), size);
            offset_ += size;
        }

    private:
        bytes_ptr bytes_;
        size_t offset_;
        bool allowLeft_;
    };

} // namespace

struct read_proc
{
    read_proc(bytes_ptr bytes)
        : g_(bytes)
    {}
    
    template<typename T>
    void operator()(T const &dst, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
    {
        g_.get(const_cast<T&>(dst));
    }

    template<typename T>
    void array(T *const ptr, size_t size, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
    {
        typedef std::remove_const<T>::type nonconst_type;
        nonconst_type* conv_ptr = const_cast<nonconst_type*>(ptr); 
        g_.get_array<nonconst_type>(conv_ptr, size);
    }

    template<typename T>
    void operator()(T const &dst, typename std::enable_if<!std::is_arithmetic<T>::value && !std::is_enum<T>::value>::type* = nullptr)
    {
        refl::process(*this, dst);
    }

    template<typename T>
    void array(T *const ptr, size_t size, typename std::enable_if<!std::is_arithmetic<T>::value && !std::is_enum<T>::value>::type* = nullptr)
    {
        T* dst = const_cast<T*>(ptr);
        for (size_t i = 0; i < size; ++i)
            this->operator()(dst[i]);
    }
    
    template<typename T, size_t N>
    void operator()(T const(&arr)[N])
    {
        array(arr, N);
    }

    template<typename T>
    T operator()()
    {
        T res;
        this->operator()(res);
        return res;
    }

private:
    inner::getter g_;
};

struct write_proc
{
    write_proc(bytes_ptr bytes)
        : bytes_(bytes)
    {}

    template<typename T>
    void operator()(T const &src, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
    {
        inner::put(src, bytes_);
    }


    template<typename T>
    void array(T *const ptr, size_t size, typename std::enable_if<std::is_arithmetic<T>::value || std::is_enum<T>::value>::type* = nullptr)
    {
        inner::put_array(ptr, size, bytes_);
    }

    template<typename T>
    void array(T *const ptr, size_t size, typename std::enable_if<!std::is_arithmetic<T>::value && !std::is_enum<T>::value>::type* = nullptr)
    {
        for (size_t i = 0; i < size; ++i)
            this->operator()(ptr[i]);
    }

    template<typename T, size_t N>
    void operator()(T const(&arr)[N])
    {
        array(arr, N);
    }

    template<typename T>
    void operator()(T const &src, typename std::enable_if<!std::is_arithmetic<T>::value && !std::is_enum<T>::value>::type* = nullptr)
    {
        refl::process(*this, src);
    }

private:
    bytes_ptr bytes_;
};

}

typedef bytes::bytes_t Bytes;
typedef bytes::bytes_ptr BytesPtr;
typedef bytes::bytes_const_ptr BytesConstPtr;
