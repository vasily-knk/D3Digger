#pragma once

namespace bytes
{

typedef vector<char> bytes_t;
typedef shared_ptr<bytes_t> bytes_ptr;
typedef shared_ptr<const bytes_t> bytes_const_ptr;
typedef int32_t size_type;

inline void reserve_additional(bytes_ptr bytes, size_t size)
{
    bytes->reserve(bytes->size() + size);
}

inline bytes_ptr make()
{
    return make_shared<bytes_t>();
}

inline bytes_ptr make(size_t size)
{
    return make_shared<bytes_t>(size);
}

template<typename T>
size_t size(T const &/*data*/)
{
    return sizeof(T);
}

inline size_t size(string const &str)
{
    return sizeof(size_type) + str.size();
}

template<typename T>
size_t size(vector<T> const &vec)
{
    size_t res = sizeof(size_type);
    BOOST_FOREACH(T const &e, vec)
        res += size(e);
    return res;
}

template<typename T>
void put(const T &data, bytes_ptr bytes, typename std::enable_if<std::is_pod<T>::value>::type* = nullptr)
{
    const size_t offset = bytes->size();
    bytes->resize(offset + size(data));
    *reinterpret_cast<T*>(&bytes->at(offset)) = data;
}

template<typename T>
void put(optional<T> const &data, bytes_ptr bytes)
{
    if (data)
    {
        put(uint8_t(1), bytes);
        put(*data, bytes);
    }
    else
    {
        put(uint8_t(0), bytes);
    }
}

/*template<typename T>
void put(T data, bytes_ptr bytes, typename std::enable_if<std::is_enum<T>::value>::type* = nullptr)
{
    put(static_cast<uint32_t>(data), bytes);
}*/

template<typename T>
void put(vector<T> const &vec, bytes_ptr bytes)
{
    reserve_additional(bytes, size(vec));
    
    put(static_cast<size_type>(vec.size()), bytes);
    BOOST_FOREACH(T const &e, vec)
        put(e, bytes);
}

inline void put(string const &vec, bytes_ptr bytes)
{
    reserve_additional(bytes, size(vec));

    put(static_cast<size_type>(vec.size()), bytes);
    BOOST_FOREACH(char const &e, vec)
        put(e, bytes);
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
        assert(allowLeft_ || left() == 0);
    }

    size_t left() const 
    {
        assert(offset_ <= bytes_->size());
        return bytes_->size() - offset_;
    }
    
    template<typename T>
    void get(T &data, typename std::enable_if<std::is_pod<T>::value>::type* = nullptr)
    {
        if(offset_ + size(data) > bytes_->size())
        {
            std::stringstream ss;
            ss << "Trying to read bytes " << offset_ << "-" << offset_ + size(data) << ", size = " << bytes_->size();
            throw error(ss.str());
        }
        data = *reinterpret_cast<T*>(&bytes_->at(offset_));
        offset_ += size(data);
    }

    template<typename T>
    void get(optional<T> &opt)
    {
        uint8_t flag;
        get(flag);
        if (flag)
        {
            opt = T();
            get(*opt);
        }
    }

    template<typename T>
    void get(vector<T> &vec)
    {
        size_type sz;
        get(sz);
        vec.resize(sz);
        BOOST_FOREACH(T &e, vec)
            get(e);
    }

    void get(string &vec)
    {
        size_type sz;
        get(sz);
        vec.resize(sz);
        BOOST_FOREACH(char &e, vec)
            get(e);
    }

    template<typename T>
    T get() 
    {
        T temp;
        get(temp);
        return temp;
    }

private:
    bytes_ptr bytes_;
    size_t offset_;
    bool allowLeft_;
};

}

typedef bytes::bytes_t Bytes;
typedef bytes::bytes_ptr BytesPtr;
typedef bytes::bytes_const_ptr BytesConstPtr;
