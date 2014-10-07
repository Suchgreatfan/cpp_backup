#include "Workshop.h"
#include "Producer.h"
#include "Consumer.h"


WorkShop::WorkShop(size_t bufferSize, 
        size_t producerSize, 
        size_t consumerSize)
:bufferSize_(bufferSize),
    buffer_(bufferSize_),
    producerSize_(producerSize),
    consumerSize_(consumerSize),
    producers_(producerSize_, NULL),
    consumers_(consumerSize_, NULL)
{
    for(std::vector<ProducerThread*>::iterator iter = producers_.begin();
            iter != producers_.end();
            ++iter)
    {
        *iter = new ProducerThread(buffer_);
    }

    for(std::vector<ConsumerThread*>::iterator iter = consumers_.begin();
            iter != consumers_.end();
            ++iter)
    {
        *iter = new ConsumerThread(buffer_);
    }
}

WorkShop::~WorkShop()
{
    for(std::vector<ProducerThread*>::iterator iter = producers_.begin();
            iter != producers_.end();
            ++iter)
    {
        delete *iter; 
    }

    for(std::vector<ConsumerThread*>::iterator iter = consumers_.begin();
            iter != consumers_.end();
            ++iter)
    {
        delete *iter;
    }
}

void WorkShop::startWorking()
{
    for(std::vector<ProducerThread*>::iterator iter = producers_.begin();
            iter != producers_.end();
            ++iter)
    {
        (*iter)->start();
    }

    for(std::vector<ConsumerThread*>::iterator iter = consumers_.begin();
            iter != consumers_.end();
            ++iter)
    {
        (*iter)->start();
    }


    for(std::vector<ProducerThread*>::iterator iter = producers_.begin();
            iter != producers_.end();
            ++iter)
    {
        (*iter)->join();
    }

    for(std::vector<ConsumerThread*>::iterator iter = consumers_.begin();
            iter != consumers_.end();
            ++iter)
    {
        (*iter)->join();
    }
}
