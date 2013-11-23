#define DEPRECATED(func, str) __declspec(deprecated) func

DEPRECATED(void MyFunc(), "Deprecated");

void MyFunc()
{
}

int main()
{
    MyFunc();
    return 0;
}
