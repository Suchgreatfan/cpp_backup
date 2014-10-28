#include "TextQuery.h"
#include <iostream>
#include <muduo/base/Logging.h>
#include <muduo/base/Timestamp.h>
using namespace muduo;

int main(int argc, char const *argv[])
{
    //Logger::setLogLevel(Logger::DEBUG);
    TextQuery query("../dict/en.dict", 
                    "../dict/zh.dict",
                    "localhost", 6379);

    std::string s;

    while(std::cin >> s)
    {
        Timestamp t1(Timestamp::now());
        std::cout << query.queryWord(s) << std::endl;
        Timestamp t2(Timestamp::now());
        std::cout << timeDifference(t2, t1) << " s" << std::endl;
    }

    return 0;
}