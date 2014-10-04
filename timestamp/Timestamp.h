#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <string>
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif /* __STDC_FORMAT_MACROS */
#include <inttypes.h>

class Timestamp
{
    public:
        Timestamp();
        Timestamp(int64_t value);

        bool isValid() const
        {return value_> 0;}

        std::string toString() const;
        std::string toFormatString() const;

        static Timestamp now();
    
    private:
        int64_t value_;
};

#endif 
