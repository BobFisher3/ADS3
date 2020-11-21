#pragma once
#include <iostream>

using namespace std;

//AVL Tree Node Class
class Node {
public:
    Node* left;
    Node* right;

    int value;
    int height;

    Node(int value) {
        this->value = value;
        left = right = nullptr;
        height = 1;
    }
};