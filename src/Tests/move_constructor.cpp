#include <utility>

class MyClass
{
    int* x;
public:
    MyClass()
    {
        x = new int;
        *x = 5;
    }
    MyClass(MyClass&& move)
    {
        x = move.x;
        move.x = 0;
    }
    ~MyClass()
    {
        delete x;
    }
};

int main()
{
    MyClass a;
    MyClass b(std::move(a));
}