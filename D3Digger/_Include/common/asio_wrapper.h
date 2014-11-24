#pragma once

struct ServiceWrapper
{
    typedef function<void(void)> Proc;
    typedef std::queue<Proc> Queue;

private:
    typedef std::mutex Mutex;
    typedef std::unique_lock<Mutex> Lock;

public:

    void post(Proc proc)
    {
        {
            Lock l(mutex_);
            queue_.push(proc);
        }
        service_.post(bind(&ServiceWrapper::process, this));
    }

    void run()
    {
        service_.run();
    }

    void stop()
    {
        service_.stop();
    }

    IOService &service()
    {
        return service_;
    }

    Queue queue() const
    {
        Lock l(mutex_);
        return queue_;
    }

private:
    void process()
    {
        Proc proc;
        {
            Lock l(mutex_);
            Assert(!queue_.empty());
            proc = queue_.front();
            queue_.pop();
        }
        
        proc();
    }

private:
    IOService service_;
    Queue queue_;
    mutable Mutex mutex_;
};