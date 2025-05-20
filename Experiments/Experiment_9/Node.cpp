#include "Node.h"

template <class T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next) {}

template <class T>
bool Node<T>::insertNext(const Node<T> *p) {
    p->next = next;
    next = p;
}

template <class T>
Node<T>* Node<T>::delNext() {
    if (!next) {
        return 0;
    } else {
        auto temp = next;
        next = next->next;
        return temp->next;
    }
}

template <class T>
Node<T> *Node<T>::nextNode() {
    return next;
}

template <class T>
const Node<T> Node<T>::nextNode() const {
    return next;
}

template <class T>
bool Node<T>::change(const T &newData) {
    data = newData;
}

template <class T>
T Node<T>::get() {
    return data;
}