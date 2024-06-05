//
// Created by jnmen on 6/1/2024.
//

#ifndef NODE_H
#define NODE_H
#include "../Drawables/NodeShape/NodeShape.h"

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;

public:
    Node(const T& data, Node<T>* next = nullptr);

    void setData(const T& data);

    T getData() const;

    void setNext(Node<T>* next);

    Node* getNext() const;

};

#include "Node.cpp"


#endif //NODE_H
