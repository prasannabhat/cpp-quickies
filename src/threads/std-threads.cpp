#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void threadProc()
{
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Message => " << i << " from " << this_thread::get_id() << endl;
        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(2s);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Waited " << elapsed.count() << " ms\n";
    }
}

int main()
{
    thread t1(threadProc);
    thread t2(threadProc);
    thread t3(threadProc);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
