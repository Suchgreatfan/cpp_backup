#include "queue.hpp"
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(int argc, const char *argv[])
{
    // Queue<string,deque<string> > qt;
    Queue<int> qt;
    qt.push(12);
    qt.push(56);
    qt.push(32);
    qt.push(74);

    Queue<double> qt2(qt);
    while(!qt2.empty())
    {
        cout << qt2.front() << endl;
        qt2.pop();
    }

    Queue<double, list<double> > qt3;
    qt3 = qt;
    while(!qt3.empty())
    {
        cout << qt3.front() << endl;
        qt3.pop();
    }
    return 0;
}
