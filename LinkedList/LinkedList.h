//
// Created by jnmen on 6/1/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <List>

template<typename T>
class LinkedList {
private:
    std::list<Node<T>*> nodes; //list of nodes

public:
    void addNode(Node<T>* node); //function to add a node to the list

    std::list<Node<T>*> getNodes(); //function to get the list of nodes

};

#include "LinkedList.cpp"

#endif //LINKEDLIST_H
