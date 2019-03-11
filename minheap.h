//
// Created by jaox on 2019-03-07.
//

#ifndef ASTAR_ALGORITHM_MINHEAP_H
#define ASTAR_ALGORITHM_MINHEAP_H

#include <vector>
#include <iostream>
#include "node.h"


using namespace std;
class MinHeap {
public:
    vector<Node*> array;
    Node* getParent(int i) {
        if(i <= 0) return nullptr;
        return array[(i-1)/2];
    }
    Node* getLeft(int i) {
        if (i<0 || (2*i+1)>=array.size()) return nullptr;
        return array[2*i+1]; //it returns null if there is no nodes in array[2*i+2]
    }
    Node* getRight(int i) {
        if(i<0 || (2*i+2)>=array.size() ) return nullptr;
        return array[2*i+2]; //it returns null if there is no nodes in array[2*i+2]
    }
    void minHeapify(int i) {
        Node* left = getLeft(i);
        Node* right = getRight(i);
        int shortest = i;
        if(left && left->key < array[i]->key) {
            shortest = 2*i+1;
        } else shortest = i;
        if(right && right->key < array[shortest]->key) {
            shortest = 2*i+2;
        }
        if(shortest != i ) {
            Node* aux = array[shortest];
            array[shortest] = array[i];
            array[shortest]->i = shortest;
            array[i] = aux;
            array[i]-> i = i ;
            minHeapify(shortest); //repeat the process where the shortest value was found
        }
    }
    Node* extractMin() {
        if(array.size()==0) return nullptr;
        Node* min = array[0];
        array[0] = array[array.size()-1];
        array[0]->i = 0;
        array.pop_back();
        minHeapify(0);
        return min;
    }
    void decreaseKey(Node* node, double key) {
        node->key = key;
        int i = node->i ;
        while(i > 0 && getParent(i)->key > key ) {
            Node* aux = getParent(i);
            array[(i-1)/2] = node;
            array[(i-1)/2]->i = aux->i;
            array[i] = aux;
            array[i]->i = i;
            i = (i-1)/2;
        }
    }
    void insertNode(Node* node, double key) {
        array.push_back(node);
        node->i = array.size()-1;
        decreaseKey(node, key);
    }
};

#endif //ASTAR_ALGORITHM_MINHEAP_H
