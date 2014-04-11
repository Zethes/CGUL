#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;

int main()
{
    std::thread myThread();
    return 0;
}
