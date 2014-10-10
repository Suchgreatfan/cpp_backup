#include "SmartPtr.hpp"
#include <iostream>
using namespace std;

class Test
{
    public:
    Test() { cout << "Test .." << endl;}
    ~Test() { cout << "Test .........." << endl; }

};

int main(int argc, char const *argv[])
{
    SmartPtr<Test> ptr(new Test);


    return 0;
}


