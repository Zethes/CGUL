#include <CGUL.hpp>
using namespace CGUL;
#include <iostream>

ConditionVariable trigger;
Mutex mutex;

bool ready;

class MyThread : public Thread
{
public:
    void Main()
    {
        while (true)
        {
            mutex.Lock();
            while (!ready)
            {
                trigger.Wait(&mutex);
            }
            std::cout << "A" << std::endl;
            Timer::Sleep(1);
            mutex.Unlock();
            ready = false;
            trigger.Signal();
        }
    }
};

int main()
{
    ready = false;

    MyThread thread;
    thread.Run();

    while (true)
    {
        mutex.Lock();
        while (ready)
        {
            trigger.Wait(&mutex);
        }
        std::cout << "B" << std::endl;
        Timer::Sleep(1);
        mutex.Unlock();
        ready = true;
        trigger.Signal();
    }
}
