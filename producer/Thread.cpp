#include "Thread.h"
#include <assert.h>
#include <unistd.h>
#include "MutexLock.h"

Thread::Thread()
    :threadId_(0),
     isRunning_(false)
{

}

Thread::~Thread()
{
    if(isRunning_)
    {
        TINY_CHECK(!pthread_detach(threadId_));
    }
}

//static
void *Thread::runInThread(void *arg)
{
    Thread *pt = static_cast<Thread*>(arg);
    //pt->tid_ = syscall(SYS_gettid);
    pt->run();
    return NULL;
}

void Thread::start()
{
    TINY_CHECK(!pthread_create(&threadId_, NULL, Thread::runInThread, this));
    isRunning_ = true;
}

void Thread::join()
{
    assert(isRunning_);
    TINY_CHECK(!pthread_join(threadId_, NULL));
    isRunning_ = false;
}
