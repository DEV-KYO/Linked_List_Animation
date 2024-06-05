//
// Created by jnmen on 6/3/2024.
//

#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

template <typename T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next) {}

template <typename T>
void Node<T>::setData(const T& data) {
    this->data = data;
}

template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

#endif //NODE_CPP