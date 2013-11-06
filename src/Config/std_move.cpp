#include <utility>

template<typename T>
typename std::remove_reference<T>::type&& check(T&& t)
{
    return t;
}

int main()
{
    int x;
    std::move(x);
    check(x);
    return 0;
}
