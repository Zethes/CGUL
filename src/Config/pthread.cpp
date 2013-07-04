#include <pthread.h>

void* mythread(void* param)
{
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, mythread, NULL);
    pthread_exit(NULL);
}
