//
// Created by jaox on 2019-03-05.
//


#include "minheap.h"
#include "graph.h"

class Astar {
    MinHeap openlist;
    Graph graph;
    Node* from = nullptr;
    Node* to = nullptr;
public:
     Astar(Graph graph1, Node* from, Node* to) {
        this->graph = graph1;
        this->from = from;
        this->to = to;
    };
    void start() {
        for(int i = 0; i < from->edges.size(); i++) {
            Node* other = from->edges[i]->nodes[1];
            double weight = from->edges[i]->weight;
            double key = weight + h(other);
            openlist.insertNode(other, key);
            other->parent = from;
            other->pweight = weight;
            other->openlist = true;
        }
        from->closed = true;
        while(openlist.array.size() != 0) {
            Node* min = openlist.extractMin();
            min->closed= true;
            for(int i = 0; i < min->edges.size(); i++) {
                Node* other = min->edges[i]->nodes[1];
                if(!other->closed) {
                    double cost = g(other) + h(other);
                    if(!other->openlist) {
                        other->parent = min;
                        other->pweight = min->edges[i]->weight;
                        other->openlist = true;
                        openlist.insertNode(other, g(other) + h(other));
                    }
                    else if(other->openlist && cost < other->key) {
                        openlist.decreaseKey(other, cost);
                        other->parent = min;
                        other->pweight = min->edges[i]->weight;
                    }
                }
            }
        }
        printPath();
    }
    double h(Node* node1) {
        int x1 = node1->posx;
        int y1 = node1->posy;
        int x2 = to->posx;
        int y2 = to->posy;
        double ans = sqrt(pow(x1-x2, 2)+pow(y1-y2,2));
        return ans;
    }
    double g(Node* node2) {
        if(node2->parent)
            return g(node2->parent) + node2->pweight;
        else return 0;
    }
    void printPath() {
        Node* pivot = to;
        while(pivot->parent) {
            cout<<pivot->parent->name<<" -> "<< pivot->name<<endl;
            pivot = pivot->parent;
        }
    }
};
