#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const Person& person, std::string& job, double salary) :
    Person(person), myJob(job), mySalary(salary) {
    cout << "又诞生了一位苦牛马" << endl;
}

bool Employee::getSalary() {
    cout << "得到了" << mySalary << "元工资" << endl;
    return true;
}

bool Employee::changeJob(string job, double salary) {
    if(job.empty() || salary <= 0){
        cout << "这不是一门正经工作" << endl;
        return false;
    }else{
        myJob = job;
        mySalary = salary;
        cout << "你的工作已经更换为" << job << "工资为" << salary << endl;
        return true;
    }
}