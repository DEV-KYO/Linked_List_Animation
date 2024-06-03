//
// Created by jnmen on 6/1/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <List>


class LinkedList {
private:
    std::list<NodeShape> nodes; //list of nodes

public:
    void addNode(const NodeShape& node); //function to add a node to the list

    std::list<NodeShape> getNodes(); //function to get the list of nodes

};



#endif //LINKEDLIST_H
