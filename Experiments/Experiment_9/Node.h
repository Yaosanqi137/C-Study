#ifndef C__STUDY_NODE_H
#define C__STUDY_NODE_H

template <class T>
class Node {
public:
    Node(const T& data, Node<T>* next = nullptr);
    bool insertNext(const Node* p);
    Node<T>* delNext();
    Node<T>* nextNode();
    const Node<T> nextNode() const;
    bool change(const T& newData);
    T get();
private:
    Node<T>* next;
    T data;
};


#endif //C__STUDY_NODE_H
