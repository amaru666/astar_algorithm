#include <iostream>
#include "graph.h"
#include "minheap.h"
#include "astar_algorithm.cpp"

int main() {
    Graph thegraph(false);
    thegraph.insertNode(0,0,0);
    thegraph.insertNode(0,1,1);
    thegraph.insertNode(0,2,2);
    thegraph.insertNode(0,3,3);
    thegraph.insertNode(1,0,5);
    thegraph.insertNode(1,1,6);
    thegraph.insertNode(1,2,7);
    thegraph.insertNode(1,3,8);
    thegraph.insertNode(2,0,10);
    thegraph.insertNode(2,1,11);
    thegraph.insertNode(2,2,12);
    thegraph.insertNode(2,3,13);
    thegraph.insertNode(3,0,15);
    thegraph.insertNode(3,1,16);
    thegraph.insertNode(3,2,17);
    thegraph.insertNode(3,3,18);


    thegraph.addEdge(0, vector{1,5,6});
    thegraph.addEdge(1, vector{6,7,2});
    thegraph.addEdge(5, vector{10,11,6});
    thegraph.addEdge(6, vector{11,7});
    thegraph.addEdge(16, vector{10,15,12,17,7});
    thegraph.addEdge(17, vector{18,12});
    thegraph.addEdge(13, vector{8,18,2});
    thegraph.addEdge(8, vector{3});

    Astar astar = Astar(thegraph, thegraph.nodes[0], thegraph.nodes[16]);
    astar.start();

    return 0;
}