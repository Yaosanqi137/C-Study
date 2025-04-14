#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const Person &person) : Person(person) {
    cout << "又诞生了一位牛马" << endl;
}

bool Student::doHomeWork() {
    if(isDoHW){
        cout << "已经在写作业了！" << endl;
        return false;
    }else if(isStudy){
        cout << "不能同时写作业同时学习" << endl;
        return true;
    }else{
        isDoHW = true;
        cout << "开始写作业了" << endl;
        return true;
    }
}

bool Student::study() {
    if(isDoHW){
        cout << "不能同时写作业同时学习" << endl;
        return false;
    }else if(isStudy){
        cout << "已经在学习了" << endl;
        return true;
    }else{
        isStudy = true;
        cout << "开始学习了" << endl;
        return true;
    }
}

Student::~Student(){
    cout << "学死了(" << endl;
}