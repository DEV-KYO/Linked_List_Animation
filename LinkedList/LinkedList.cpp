//
// Created by jnmen on 6/1/2024.
//

#include "LinkedList.h"

void LinkedList::addNode(const NodeShape &node) {
    // Adds a node to the list
    nodes.push_back(node);
}

std::list<NodeShape> LinkedList::getNodes() {
    // Returns the list of nodes
    return nodes;
}