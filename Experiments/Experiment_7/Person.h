#ifndef C__STUDY_PERSON_H
#define C__STUDY_PERSON_H

class Person {
public:
    explicit Person(bool sexIn);
    Person(const Person& person) = default;
    bool eat();
    bool sleep();
    bool addAge();
    ~Person();

protected:
    bool getSex();

public:
    const bool sex;
    int age = 18;
    bool isSleep = false;
};


#endif //C__STUDY_PERSON_H
