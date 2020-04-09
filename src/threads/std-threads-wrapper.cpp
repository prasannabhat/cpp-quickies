#include "std-threads.hpp"

int main()
{
    Thread t1, t2, t3;
    t1.start();
    t2.start();
    t3.start();

    t1.detach();
    t2.detach();
    t3.detach();

    this_thread::sleep_for(3s);

    t1.stop();
    t2.stop();
    t3.stop();
    this_thread::sleep_for(3s);
    return 0;
}