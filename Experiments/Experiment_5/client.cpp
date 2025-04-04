#include <iostream>
#include "time.h"
using namespace std;

int main(){
    system("chcp 65001");
    Time time;
    time.setTime(12, 30, 5); // 设置合法时间
    time.showTime(); // 显示时间
    time.setTime(25, 30, 5); // 设置非法时间
    time.showTime(); // 依然显示原来的时间
    return EXIT_SUCCESS;
}
