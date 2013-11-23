#define DEPRECATED(func, str) func __attribute__ ((deprecated(str)))

DEPRECATED(void MyFunc(), "Deprecated");

void MyFunc()
{
}

int main()
{
    MyFunc();
    return 0;
}
