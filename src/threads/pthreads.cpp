#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void* threadProc(void* param)
{
    for (int count = 0; count < 1000; ++count)
    {
        // These are thread IDs assigned by pthread library
        // This will be different compared to OS thread ID
        // How to get OS thread id ?
        // ps -A | grep <app-name> -> This returns process ID
        // ps -T -p <process-id> OR
        // top -H -p <process-id>

        // pthread_id_np_t tid;
        // pthread_getthreadid_np();
        cout << "Message " << count << " from " << pthread_self() << " : " << endl;
        sleep(1);
    }

    pthread_exit(0);
}

int main()
{
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, threadProc, NULL);
    pthread_create(&thread2, NULL, threadProc, NULL);
    pthread_create(&thread3, NULL, threadProc, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}