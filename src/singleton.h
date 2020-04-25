#pragma once

#include <memory>

template <typename T>
class Singleton
{
public:
    typedef T object_type;
    typedef std::shared_ptr<T>  object_type_ptr;

    Singleton() = default;

    static object_type & instance() { return *getInstance(); };

    static object_type_ptr getInstance()
    {
        if (!sInstance)
        {
            sInstance.reset(new T());
        }

        return sInstance;
    };

    static void removeInstance()
    {
        sInstance.reset();
    }

private:

    static object_type_ptr sInstance;
};

#define SINGLETON( t )      \
friend class Singleton<t>
