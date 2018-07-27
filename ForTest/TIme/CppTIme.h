//
// Created by san on 7/27/18.
//
//标准C库函数对于时间有多种表示，它们都是class Time的一部分，但全部更新它们没有必要。所以time _t t被用作基本但表示法。tm local和ASCII字符表示
//法asciiRep都有一个标记来显示它们是否已被更新为当前时间time_t。两个私有函数updateLocal() 和 updateAscii()检查标记，并有条件地执行更新操作。

#ifndef CPPTIME_H
#define CPPTIME_H
#include <ctime>
#include <cstring>

class Time {
public:
    Time() { mark(); }

    void mark() {             //清除了两个标记
        lflag = aflag = 0;
        std::time(&t);
    }

    const char *ascii() {     //返回值就是内部缓冲器地址
        updateAscii();
        return asciiRep;
    }

    //Difference in seconds:
    int delta(Time *dt) const {
        return int(std::difftime(t, dt->t));
    }

    int daylightSavings() {
        updateLocal();
        return local.tm_isdst;
    }

    int dayOfYear()      //   Since January 1
    {
        updateLocal();
        return local.tm_yday;
    }

    int dayOfWeek()      // Since Sunday
    {
        updateLocal();
        return local.tm_wday;
    }

    int since1900()     // Years since 1900
    {
        updateLocal();
        return local.tm_year;
    }

    int month()         // Since January
    {
        updateLocal();
        return local.tm_mon;
    }

    int dayOfMonth() {
        updateLocal();
        return local.tm_mday;
    }

    int hour()     // Since midnight, 24-hour clock
    {
        updateLocal();
        return local.tm_hour;
    }
    int minute()
    {
        updateLocal();
        return local.tm_min;
    }
    int second()
    {
        updateLocal();
        return local.tm_sec;
    }

private:
    std::time_t t;
    std::tm local;
    char asciiRep[26];
    unsigned char lflag, aflag;
    void updateLocal()
    {
        if(!lflag)
        {
            local = *std::localtime(&t);
            ++lflag;
        }
    }
    void updateAscii()    //把标准C库函数的结果拷贝到局部缓冲器里，
    {
        if(!aflag)
        {
            updateLocal();
            std::strcpy(asciiRep,std::asctime(&local));
            ++aflag;
        }
    }
};
#endif   //CPPTIME_H   /// :~
