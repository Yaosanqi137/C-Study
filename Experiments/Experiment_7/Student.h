#ifndef C__STUDY_STUDENT_H
#define C__STUDY_STUDENT_H
#include "Person.h"

class Student : virtual public Person{
public:
    explicit Student(const Person& person);
    bool doHomeWork();
    bool study();
    ~Student();
private:
    bool isStudy = false;
    bool isDoHW = false;
};


#endif //C__STUDY_STUDENT_H
