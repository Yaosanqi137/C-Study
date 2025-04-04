#ifndef TIME_H
#define TIME_H

class Time{
public:
    Time();
    bool showTime();
    bool setTime(int, int, float);
    bool isTimeLegal(int, int, float);
private:
    int hour;
    int minute;
    float second;
};

#endif //TIME_H
