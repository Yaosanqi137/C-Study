#ifndef C__STUDY_LIST_H
#define C__STUDY_LIST_H

template <class T>
class List {
public:
    List(const T& data, List<T>* next = nullptr, List<T>* previous = nullptr);
    List(const List<T>& List);
    ~List();
    List<T> operator=(const List<T>& List);

    int getSize() const;
    bool isEmpty() const;

    void reset(int pos = 0);
    void next();
    bool endOfList() const;
    int currentPosition() const;

    void insertFront(const T& item);
    void insertRear(const T& item);
    void insertAt(const T& item);
    void insertAfter(const T& item);

    T deleteFront();
    void deleteCurrent();

    T& data();
    const T& data() const;

    void clear();

private:
    List<T>* after, previous;
    List<T>* begin, end;
    T DATA;
    int count = 0;
    int pos;

    List<T>* newNode(const T &item, List<T>* nextPtr = nullptr);
    void freeNode(List<T>* p);
    void copy(const List<T>& List);
};


#endif //C__STUDY_LIST_H
