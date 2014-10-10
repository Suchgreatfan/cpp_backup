#ifndef SMART_PTR_
#define SMART_PTR_ 

#include <stddef.h>

template <typename T>
class SmartPtr
{
    public:
    SmartPtr(T *ptr=NULL);
    ~SmartPtr() {delete ptr_;}

    T &operator*() const { return *ptr_;}
    T *operator->() const { return ptr_;}

    const T *getPtr() const {return ptr_;}

    void resetPtr(T *ptr = NULL);
    

    private:
    SmartPtr &operator=(SmartPtr &);
    SmartPtr(SmartPtr &);
        
    T *ptr_;
};


template <typename T>
SmartPtr<T>::SmartPtr(T *ptr)
    :ptr_(ptr)
{
    
}

template <typename T>
void SmartPtr<T>::resetPtr(T *ptr)
{
    if(ptr_!=ptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }
}



#endif  /* SMART_PTR_ */
