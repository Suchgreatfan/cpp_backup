#ifndef CONSUMER_H
#define CONSUMER_H

#include "Thread.h"

class Buffer;

class ConsumerThread : public Thread
{
public:
    ConsumerThread(Buffer &buffer);
    void run();
private:
    Buffer &buffer_;
};

#endif //CONSUMER_H
