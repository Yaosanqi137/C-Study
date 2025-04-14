#ifndef C__STUDY_EMPLOYEE_H
#define C__STUDY_EMPLOYEE_H
#include "Person.h"
#include <string>

class Employee : virtual public Person{
public:
    explicit Employee(const Person& person, std::string& job, double salary);

protected:
    bool getSalary();
    bool changeJob(std::string job, double salary);

private:
    std::string myJob;
    double mySalary;
};


#endif //C__STUDY_EMPLOYEE_H
