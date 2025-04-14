#include "PartTime_Graduate_Student.h"
#include <iostream>
using namespace std;

PartTime_Graduate_Student::PartTime_Graduate_Student(
        const Person& person, const Student &student, const Employee &employee) :
    Student(student), Employee(employee), Person(person) {
    cout << "又诞生了一位超级牛马" << endl;
}