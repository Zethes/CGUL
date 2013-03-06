#include <Jatta.h>
#include <cstdio>
#include <cstdlib>

#define SLEEP_TIME 1000
#define LEE_WAY 10

int main() 
{
    Jatta::Timer* timer = new Jatta::Timer();

    //Make sure it's created correctly
    if (timer == NULL)
    { 
        printf("Failed to initialize Jatta::Timer.\n");
        return EXIT_FAILURE; 
    }

    //sleep for x time, then see if it was around taht time.
    timer->Start();
    timer->Sleep(SLEEP_TIME);

    Jatta::UInt32 sleepTime = timer->GetElapsedMiliseconds();
    if (sleepTime > SLEEP_TIME+LEE_WAY)
    { 
        printf("Slept for either too long. Time: %d\n", sleepTime);
        return EXIT_FAILURE; 
    }
    if (sleepTime < SLEEP_TIME-LEE_WAY)
    { 
        printf("Slept for either too short. Time: %d\n", sleepTime);
        return EXIT_FAILURE; 
    }

    //Cleanup test
    timer->Stop();
    delete timer;
    timer = NULL;
    if (timer != NULL)
    { 
        printf("Failed to deinitialize Jatta::Timer.\n");
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS;
}