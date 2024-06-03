//
// Created by jnmen on 6/1/2024.
//

#ifndef NODE_H
#define NODE_H
#include "../Drawables/NodeShape/NodeShape.h"

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    explicit Node(const NodeShape& data, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {}

};

#endif //NODE_H
