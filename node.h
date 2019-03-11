//
// Created by jaox on 2019-03-07.
//

#ifndef ASTAR_ALGORITHM_NODE_H
#define ASTAR_ALGORITHM_NODE_H
#include <vector>

using namespace std;

class Edge;

class Node {
public:
    vector<Edge*> edges = {};
    int posx=0;
    int posy=0;
    int name=0;
    Node* parent = nullptr; //this is used by a*
    double pweight = 0; //this is used by a*
    double key = -1; //f = g + h
    int i = -1; //priority queue needs it, because every node has a index that is updated when position changes
    bool closed = false; //this is used by a*
    bool openlist = false; //this is used by a*
    Node(int posx, int posy, int name): posx{posx}, posy{posy}, name{name} {}
};

#endif //ASTAR_ALGORITHM_NODE_H
