#include <Jatta.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    if (!Jatta::File::WriteText(JSTR("ひらがな.txt"), JSTR("こんにちは")))
    {
        return EXIT_FAILURE;
    }

    Jatta::String result;
    if (!Jatta::File::ReadText(JSTR("ひらがな.txt"), &result))
    {
        return EXIT_FAILURE;
    }

    if (result != JSTR("こんにちは"))
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}