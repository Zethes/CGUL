#define DEPRECATED(func, str) func __attribute__ ((deprecated))

DEPRECATED(void MyFunc(), "Deprecated");

void MyFunc()
{
}

int main()
{
    MyFunc();
    return 0;
}
