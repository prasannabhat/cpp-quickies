// Courtesy : https://vorbrodt.blog/2019/02/21/memory-barriers-and-thread-synchronization/

#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char** argv)
{
    bool flag = false;

    thread t1([&]() {
        this_thread::sleep_for(1000ms);
        cout << "t1 started" << endl;
        flag = true;
        cout << "t1 signals and exits" << endl;
    });

    thread t2([&]() {
        cout << "t2 started" << endl;
        while (flag == false)
            ;
        cout << "t2 got signaled and exits" << endl;
    });

    t1.join();
    t2.join();

    return 1;
}