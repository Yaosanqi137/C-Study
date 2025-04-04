#include <iomanip>
#include <iostream>
#include "time.h"
using namespace std;

Time::Time() : hour(0), minute(0), second(0) {}

bool Time::isTimeLegal(int hh, int mm, float ss) {
    if(hh <= 24 && mm < 60 && ss < 60.f
       && hh >= 0 && mm >= 0 && ss >= 0.f){
        return true;
    }else{
        return false;
    }
}

bool Time::showTime() {
    if(isTimeLegal(hour, minute, second)){
        cout << fixed << setprecision(2) << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(5) << setfill('0') << second << endl;
        return true;
    }else{
        cout << "错误的时间格式！请重新设置时间！" << endl;
        return false;
    }
}

bool Time::setTime(int hh, int mm, float ss) {
    if(isTimeLegal(hh, mm, ss)){
        hour = hh;
        minute = mm;
        second = ss;
        return true;
    }else{
        cout << "错误的时间格式！请重新设置时间！" << endl;
        return false;
    }
}
