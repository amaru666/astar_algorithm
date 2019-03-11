//
// Created by jaox on 2019-03-11.
//

#ifndef ASTAR_ALGORITHM_GRAPH_H
#define ASTAR_ALGORITHM_GRAPH_H

#include "edge.h"
#include "node.h"
#include <unordered_map>
#include <iostream>

using namespace std;

struct Graph {
    vector<Edge*> edges;
    unordered_map<int,Node*> nodes;
    bool directed;
    Graph(){}
    Graph(bool directed) : directed(directed) {}

    void insertNode(int x, int y, int name){
        Node* node = new Node(x,y,name);
        nodes[name] = node;
    }

    void addEdge(int from, const vector<int> &listAdjacency){
        for(int i = 0; i < listAdjacency.size(); i++) {
            Node* node = nodes[from];
            Node* other = nodes[listAdjacency[i]];
            Edge* edge = new Edge(distance(node,other));
            edge->nodes[0] = node;
            edge->nodes[1] = other;
            node->edges.push_back(edge);
            edges.push_back(edge);
            if(!directed) {
                Edge* edge2 = new Edge(distance(node, other));
                edge2->nodes[0] = other;
                edge2->nodes[1] = node;
                other->edges.push_back(edge2);
            }
        }
    }
    double distance(Node* a, Node* b) {
        return sqrt(pow((a->posx)-(b->posx),2)+pow((a->posy)-(b->posy),2));
    }
};

#endif //ASTAR_ALGORITHM_GRAPH_H
