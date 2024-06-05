//
// Created by jnmen on 6/1/2024.
//

#ifndef LinkedList_CPP
#define LinkedList_CPP
#include "LinkedList.h"

template<typename T>
void LinkedList<T>::addNode(Node<T>* node) {
    nodes.push_back(node);
}

template<typename T>
std::list<Node<T>*> LinkedList<T>::getNodes() {
    return nodes;
}


#endif //LinkedList_CPP