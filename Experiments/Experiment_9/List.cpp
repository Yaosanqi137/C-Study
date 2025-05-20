#include "List.h"
#include <iostream>
using namespace std;

template <class T>
List<T>::List(const T& data, List<T>* next, List<T>* prev) :
        DATA(data), after(next), previous(prev), begin(this), end(this), count(1), pos(0) {}

template <class T>
List<T>::List(const List<T>& other) : after(nullptr), previous(nullptr), begin(nullptr), end(nullptr), count(0), pos(0) {
    copy(other);
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
List<T> List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <class T>
int List<T>::getSize() const {
    return count;
}

template <class T>
bool List<T>::isEmpty() const {
    return count == 0;
}

template <class T>
void List<T>::reset(int position) {
    if (position < 0 || position >= count) {
        pos = 0;
        after = begin;
        previous = nullptr;
        return;
    }

    pos = position;
    after = begin;
    previous = nullptr;

    for (int i = 0; i < position && after != nullptr; i++) {
        previous = after;
        after = after->after;
    }
}

template <class T>
void List<T>::next() {
    if (after != nullptr) {
        previous = after;
        after = after->after;
        pos++;
    }
}

template <class T>
bool List<T>::endOfList() const {
    return after == nullptr;
}

template <class T>
int List<T>::currentPosition() const {
    return pos;
}

template <class T>
void List<T>::insertFront(const T& item) {
    List<T>* node = new List<T>(item, begin);

    if (isEmpty()) {
        end = node;
    } else {
        begin->previous = node;
    }

    begin = node;
    count++;
    reset(pos);
}

template <class T>
void List<T>::insertRear(const T& item) {
    List<T>* node = new List<T>(item);

    if (isEmpty()) {
        begin = end = node;
    } else {
        end->after = node;
        node->previous = end;
        end = node;
    }

    count++;
}

template <class T>
void List<T>::insertAt(const T& item) {
    if (pos == 0) {
        insertFront(item);
    } else if (pos >= count) {
        insertRear(item);
    } else {
        List<T>* node = new List<T>(item, after);
        previous->after = node;
        node->previous = previous;

        if (after != nullptr) {
            after->previous = node;
        }

        after = node;
        count++;
    }
}

template <class T>
void List<T>::insertAfter(const T& item) {
    if (after == nullptr) {
        insertRear(item);
    } else {
        List<T>* node = new List<T>(item, after->after);
        after->after = node;
        node->previous = after;

        if (node->after != nullptr) {
            node->after->previous = node;
        } else {
            end = node;
        }

        count++;
    }
}

template <class T>
T List<T>::deleteFront() {
    if (isEmpty()) {
        cout << "链表是空的" << endl;
    }

    List<T>* temp = begin;
    T data = temp->DATA;

    begin = begin->after;
    if (begin != nullptr) {
        begin->previous = nullptr;
    } else {
        end = nullptr;
    }

    delete temp;
    count--;
    reset(pos);
    return data;
}

template <class T>
void List<T>::deleteCurrent() {
    if (after == nullptr) {
        cout << "无法删除一个不存在的节点" << endl;
    }

    List<T>* temp = after;

    if (previous != nullptr) {
        previous->after = after->after;
    } else {
        begin = after->after;
    }

    if (after->after != nullptr) {
        after->after->previous = previous;
    } else {
        end = previous;
    }

    after = after->after;
    delete temp;
    count--;
}

template <class T>
T& List<T>::data() {
    if (after == nullptr) {
        cout << "不存在的节点" << endl;
    }
    return after->DATA;
}

template <class T>
const T& List<T>::data() const {
    if (after == nullptr) {
        cout << "不存在的节点" << endl;
    }
    return after->DATA;
}

template <class T>
void List<T>::clear() {
    List<T>* current = begin;
    while (current != nullptr) {
        List<T>* next = current->after;
        delete current;
        current = next;
    }
    begin = end = after = previous = nullptr;
    count = 0;
    pos = 0;
}

template <class T>
void List<T>::copy(const List<T>& other) {
    List<T>* current = other.begin;
    while (current != nullptr) {
        insertRear(current->DATA);
        current = current->after;
    }
    reset();
}