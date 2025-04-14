#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "PartTime_Graduate_Student.h"
using namespace std;

int main(){
    system("chcp 65001");
    bool sex = true;
    Person dwt(sex);
    Student student(dwt);
    student.study();
    string str = "程序员";
    Employee work(dwt, str, 5000.0);
    work.addAge();
    PartTime_Graduate_Student pgs(dwt, student, work);
    return EXIT_SUCCESS;
}