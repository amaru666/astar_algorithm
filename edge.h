//
// Created by jaox on 2019-03-11.
//

#ifndef ASTAR_ALGORITHM_EDGE_H
#define ASTAR_ALGORITHM_EDGE_H

class Node;

class Edge {
public:
    Node* nodes[2];
    double weight;
    Edge(double weight) : weight(weight) {}
};


#endif //ASTAR_ALGORITHM_EDGE_H
