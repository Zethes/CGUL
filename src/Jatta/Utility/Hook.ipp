/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template<typename T> typename Jatta::Hook<T>::Type Jatta::Hook<T>::Attach(Type func)
{
    functions.push_back(func);
    return func;
}

template<typename T> bool Jatta::Hook<T>::Remove(typename Jatta::Hook<T>::Type func)
{
    for (typename std::vector<Type>::iterator it = functions.begin(); it != functions.end(); it++)
    {
        functions.erase(it);
        return true;
    }
    return false;
}

template<typename T> void Jatta::Hook<T>::Call(T parameter)
{
    for (typename std::vector<Type>::iterator it = functions.begin(); it != functions.end(); it++)
    {
        (*it)(parameter);
    }
}