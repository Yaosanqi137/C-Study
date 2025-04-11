#include <iostream>
#include <iomanip>
using namespace std;

class Time{
public:
    explicit Time() :
        second(0.f), minute(0), hour(0) {};

    explicit Time(const float &ss, const int &mm, const int &hh) :
        second(ss), minute(mm), hour(hh) {} ;

    Time(const Time &time) = default;

    void setTime(const float &ss, const int &mm, const int &hh) {
        second = ss;
        minute = mm;
        hour   = hh;
    }

    void showTime() const {
        cout << fixed << setprecision(2) << hour << ":" << minute << ":" << second << endl;
    }

private:
    float second;
    int minute;
    int hour;
};

int main(){
    Time *TIMES = new Time();
    TIMES->showTime();
    delete TIMES;

    TIMES = new Time(1, 4, 5);
    delete TIMES;
    // 使用 new 和 delete 创建和撤销对象

    Time *timeArr = new Time[3];
    timeArr->setTime(1, 1, 4);
    timeArr[1].setTime(5, 1, 4);
    (*(timeArr + 2)).setTime(1, 9, 1);
    for(int i = 0; i < 3; i++)
        (timeArr + i)->showTime();
    for(int i = 0; i < 3; i++)
        timeArr[i].showTime();
    delete[] timeArr;
    // 数组下标和指针遍历

    return EXIT_SUCCESS;
}