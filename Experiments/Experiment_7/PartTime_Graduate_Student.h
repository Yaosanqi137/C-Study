#ifndef C__STUDY_PARTTIME_GRADUATE_STUDENT_H
#define C__STUDY_PARTTIME_GRADUATE_STUDENT_H
#include "Student.h"
#include "Employee.h"

class PartTime_Graduate_Student : public Student, public Employee{
public:
    PartTime_Graduate_Student(const Person& person, const Student& student, const Employee& employee);
};


#endif //C__STUDY_PARTTIME_GRADUATE_STUDENT_H
