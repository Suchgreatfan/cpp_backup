#include "Producer.h"
#include "Buffer.h"
#include <iostream>
#include <stdlib.h>

ProducerThread::ProducerThread(Buffer &buffer)
    :buffer_(buffer)
{
    ::srand(12345);
}

void ProducerThread::run()
{
    while(1)
    {
        int num = rand() % 100;
        std::cout << "push a num : " << num << std::endl;
        buffer_.push(num);

        sleep(2);
    }
}