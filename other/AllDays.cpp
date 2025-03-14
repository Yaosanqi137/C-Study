// 有了 ctime 再也不用像之前牢李一样手写啦
#include <iostream>
#include <ctime>
using namespace std;

string formatTime(time_t time){
    tm *tm = localtime(&time);
    char buffer[32];
    strftime(buffer, 32, "%Y-%m-%d", tm);
    return string(buffer);
}

void calDay(){
    tm start = {0};
    time_t start_time;
    int days;
    cout << "请输入开始时间(年 月 日,不能小于1900年,输入-1为当前时间):";
    cin >> start.tm_year;
    if(start.tm_year != -1){
        cin >> start.tm_mon >> start.tm_mday;
        start.tm_year -= 1900;
        start.tm_mon -= 1;
        start_time = mktime(&start);
        if(start_time == -1){
            cerr << "时间单位转换失败，请确保输入的时间正确!" << endl;
            exit(EXIT_FAILURE);
        }
    }else{
        start_time = time(0);
        start_time -= start_time % 86400 + 28800; // 纠正时差-测试机器为Asia/Shanghai
    }
    cout << "请输入目标天数(允许负数)" << endl;
    cin >> days;
    // 获取日期

    time_t result = start_time + days * 3600 * 24;
    cout << formatTime(start_time) << "经过" << days << "天后是" << formatTime(result) << endl << endl;
}

void getDay(){
    tm start = {0}, end = {0};
    cout << "请输入开始时间(年 月 日,不能小于1900年,输入-1为当前时间):";
    cin >> start.tm_year;
    if(start.tm_year != -1){
        cin >> start.tm_mon >> start.tm_mday;
        start.tm_year -= 1900;
        start.tm_mon -= 1;
    }
    cout << "请输入结束时间(年 月 日,不能小于1900年,输入-1为当前时间):";
    cin >> end.tm_year;
    if(end.tm_year != -1){
        cin >> end.tm_mon >> end.tm_mday;
        end.tm_year -= 1900;
        end.tm_mon -= 1;
    }
    // 获取日期

    time_t start_time;
    if(start.tm_year != -1)
        start_time = mktime(&start);
    else{
        start_time = time(0);
        start_time -= start_time % 86400 + 28800; // 纠正时差-测试机器为Asia/Shanghai
    }
    time_t end_time;
    if(end.tm_year != -1)
        end_time = mktime(&end);
    else{
        end_time = time(0);
        end_time -= end_time % 86400 + 28800; // 纠正时差-测试机器为Asia/Shanghai
    }
    if(start_time == -1 || end_time == -1){
        cerr << "时间单位转换失败，请确保输入的时间正确!" << endl;
        exit(EXIT_FAILURE);
    }
    // 日期转换和防错误输入

    int result = difftime(end_time, start_time) / 86400;
    cout << "从" << formatTime(start_time) << "到" << formatTime(end_time) << "一共经过了"<< result << "天" << endl << endl;
}

int main(){
    system("chcp 65001");
    char choice;
    cout << "**欢迎来到时间计算器!**" << endl << endl;
    while(true){
        cout << "请输入你想要使用的功能" << endl;
        cout << "A.计算两个日期之间差多少天" << endl;
        cout << "B.推算某日期几天后的日期" << endl;
        cout << "C.获取现在的时间" << endl;
        cout << "D.退出" << endl;
        cout << "请输入选项:";
        cin >> choice;
        if(choice == 'D')
            break;
        switch(choice){
            case 'A':
                getDay();
                break;
            case 'B':
                calDay();
                break;
            case 'C':
                cout << "现在是:" << formatTime(time(0)) <<endl;
                break;
        }
    }
    cout << "程序已退出" << endl;
    return EXIT_SUCCESS;
}