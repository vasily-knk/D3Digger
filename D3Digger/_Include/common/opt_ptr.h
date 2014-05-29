#pragma once

template<typename T>
optional<T> ptr2opt(T const *p)
{
    if (p)
        return *p;
    else
        return boost::none;
}

template<typename T>
T const *opt2ptr(optional<T> const &opt)
{
    if (opt)
        return &(*opt);
    else
        return nullptr;
}

template<typename T>
T *opt2ptr(optional<T> &opt)
{
    if (opt)
        return &(*opt);
    else
        return nullptr;
}
