#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(bool sexIn) : sex(sexIn) {
    cout << "世界上又多了一个人，" << endl;
    getSex();
}

bool Person::eat() {
    cout << "我吃好了" << endl;
    return true;
}

bool Person::sleep() {
    if(isSleep){
        cout << "已经在睡觉了！" << endl;
        return false;
    }else{
        cout << "睡觉了" << endl;
        return true;
    }
}

Person::~Person() {
    cout << "我死啦！" << endl;
}

bool Person::addAge() {
    age++;
    cout << "又多了一岁" << endl;
    return true;
}

bool Person::getSex() {
    if(sex){
        cout << "你是男的" << endl;
    }else{
        cout << "你是女的" << endl;
    }
    return true;
}


