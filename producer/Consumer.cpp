#include "Consumer.h"
#include "Buffer.h"
#include <iostream>

ConsumerThread::ConsumerThread(Buffer &buffer)
    :buffer_(buffer)
{

}


void ConsumerThread::run()
{
    while(1)
    {
        int num = buffer_.pop();
        std::cout << "pop a num : " << num << std::endl;  
        
        sleep(3);
    }
}
