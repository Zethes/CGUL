// a qualified enum is an enum that can use the scope resolution (::) operator

enum MyEnum
{
    ASDF,
    BLAH
}

int main()
{
    MyEnum type = MyEnum::ASDF;
    return 0;
}