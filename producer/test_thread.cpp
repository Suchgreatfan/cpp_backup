#include "Thread.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class MyThread : public Thread
{
public:
    void run()
    {
        cout << "foo" << endl;
    }
};

int main(int argc, char const *argv[])
{
    MyThread t;
    t.start();

    t.join();

    return 0;
}