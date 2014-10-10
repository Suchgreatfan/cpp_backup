#include <iostream>
#include <string>
#include <assert.h>
#include "CountPtr.hpp"
using namespace std;

class Test
{
    public:
        Test() { cout<< "Test" << endl; }
        ~Test() {cout <<"~Test" << endl; }

    private:
        Test(const Test &);
        void operator=(const Test &);
};

int main(int argc, const char *argv[])
{
    CounterPtr<Test> ptr(new Test);
    cout << ptr.count() << endl;

    CounterPtr<Test> ptr2(ptr);
    cout << ptr2.count() << endl;

    CounterPtr<Test> ptr3;
    ptr3 = ptr;
    cout << ptr.count() <<endl;

    if(ptr)
    {
        cout << "not NULL" <<  endl;
    }

    return 0;
}
