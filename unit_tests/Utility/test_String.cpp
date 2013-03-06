#include <Jatta.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

int main() 
{
    Jatta::String* testString1 = new Jatta::String();

    //Make sure it's created correctly
    if (testString1 == NULL)
    { 
        printf("Failed to initialize Jatta::String.\n");
        return EXIT_FAILURE; 
    }

    //Cleanup test
    delete testString1;
    testString1 = NULL;
    if (testString1 != NULL)
    { 
        printf("Failed to deinitialize Jatta::String.\n");
        return EXIT_FAILURE; 
    }

    //Test GetCString
    if (strcmp("GetCString", Jatta::String("GetCString").GetCString()) != 0)
    { 
        printf("Jatta::String::GetCString failed.\n");
        return EXIT_FAILURE; 
    }

    //Test GetData
    if (Jatta::String("GetData").GetData().compare("GetData") != 0)
    { 
        printf("Jatta::String::GetData failed.\n");
        return EXIT_FAILURE; 
    }

    Jatta::String testPrefix = "Test ";

    //Test +
    Jatta::String test1 = testPrefix + "one";
    if (test1.GetData().compare("Test one") != 0)
    { 
        printf("Add operator for Jatta::String failed. Have: '%s'\n", test1.GetCString());
        return EXIT_FAILURE; 
    }

    //Test ==
    Jatta::String test2 = testPrefix + "two";
    if (test2 != Jatta::String("Test two"))
    { 
        printf("Equal operator for Jatta::String failed. Have: '%s'\n", test2.GetCString());
        return EXIT_FAILURE; 
    }

    //Test + with non-string
    Jatta::String test3 = testPrefix;
    test3 += 3;
    if (test3 != Jatta::String("Test 3"))
    { 
        printf("Add non-string operator for Jatta::String failed. Have: '%s'\n", test3.GetCString());
        return EXIT_FAILURE; 
    }

    //Test ToUpper
    Jatta::String test4 = testPrefix + "four";
    test4.ToUpper();
    if (test4 != Jatta::String("TEST FOUR"))
    { 
        printf("Jatta::String::ToUpper failed. Have: '%s'\n", test4.GetCString());
        return EXIT_FAILURE; 
    }

    //Test ToLower
    Jatta::String test5 = testPrefix + "five";
    test5.ToLower();
    if (test5 != Jatta::String("test five"))
    { 
        printf("Jatta::String::ToLower failed. Have: '%s'\n", test5.GetCString());
        return EXIT_FAILURE; 
    }

    //Test Remove Whitespace
    Jatta::String test6 = testPrefix + "six";
    test6.RemoveWhitespace();
    if (test6 != Jatta::String("Testsix"))
    { 
        printf("Jatta::String::RemoveWhitespace failed. Have: '%s'\n", test6.GetCString());
        return EXIT_FAILURE; 
    }

    //Test Explode
    Jatta::String test7 = testPrefix + "seven";
    std::vector<Jatta::String> test7Result = test7.Explode(" ");
    if (test7Result.size() < 2 || test7Result[0] != Jatta::String("Test") || test7Result[1] != Jatta::String("seven"))
    { 
        printf("Jatta::String::Explode failed. Have %d entries: ", test7Result.size());
        for (unsigned int i = 0; i < test7Result.size(); i++)
        {
            printf("'%s' ", test7Result[i].GetCString());
        }
        printf("\n");
        return EXIT_FAILURE; 
    }

    //Test Substring
    Jatta::String test8 = testPrefix.SubString(1,3);
    if (test8 != Jatta::String("est"))
    { 
        printf("Jatta::String::Substring failed. Have: '%s'\n", test8.GetCString());
        return EXIT_FAILURE; 
    }

    //Test Find First
    Jatta::String test9 = testPrefix + "Test nine";
    if (test9.FindFirstOf("Test") != 0)
    { 
        printf("Jatta::String::FindFirstOf failed. Have: '%s' (%d)\n", test9.GetCString(), test9.FindFirstOf("Test"));
        return EXIT_FAILURE; 
    }

    //Test Find Last
    Jatta::String test10 = testPrefix + "Test nine";
    if (test10.FindLastOf("Test") != 5)
    { 
        printf("Jatta::String::FindLastOf failed. Have: '%s' (%d)\n", test10.GetCString(), test10.FindLastOf("Test"));
        return EXIT_FAILURE; 
    }

    //Test Is
    Jatta::String test11 = "7.1";
    if (!test11.Is<float>())
    { 
        printf("Jatta::String::Is failed. Have: '%s' (%d)\n", test11.GetCString(), test11.Is<float>());
        return EXIT_FAILURE; 
    }

    //Test To
    if (test11.To<float>() != 7.1f)
    { 
        printf("Jatta::String::Is failed. Have: '%s' (%f)\n", test11.GetCString(), test11.To<float>());
        return EXIT_FAILURE; 
    }

    //DONE
    return EXIT_SUCCESS;
}