#include <iostream>
#include <thread>
using namespace std;
class Thread
{
  protected:
    thread* pThread;
    bool stopped;
    void run()
    {
        while (!stopped)
        {
            cout << "In Thread " << this_thread::get_id() << endl;
            this_thread::sleep_for(1s);
        }
        cout << "\nThread " << this_thread::get_id() << " stopped as requested." << endl;
        return;
    }

  public:
    Thread()
    {
        pThread = nullptr;
        stopped = false;
    }
    ~Thread()
    {
        cout << "Thread destructor " << endl;
        delete pThread;
    }
    void start()
    {
        pThread = new thread(&Thread::run, this);
        stopped = false;
    }

    void start(thread* thread)
    {
        pThread = thread;
        stopped = false;
    }

    void stop()
    {
        stopped = true;
    }

    void join()
    {
        pThread->join();
    }
    void detach()
    {
        pThread->detach();
    }
};