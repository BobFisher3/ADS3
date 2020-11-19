#pragma once
#include <iostream>
#include<queue>
#include "Node.h"
#include <fstream>

using namespace std;

//AVL Tree Class
class AVL
{
public:

    //Function to get height of the tree
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    //Updates the height value when an element is added
    Node* updateHeight(Node* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return node;
    }

    //Function to add an element to the AVL Tree
    Node* insert(Node* root, int value) {
        //Create a new node if there is no root (tree is empty)
        if (root == nullptr) { 
            return new Node(value);
        }

        if (root->value < value) {
            root->right = insert(root->right, value);
        }
        else if (root->value == value) {
            cout << "value: " << value << " Can't have a duplicate" << endl;
            return root;
        }
        else {
            root->left = insert(root->left, value);
        }

        root = updateHeight(root);

        //Prevent the tree from becoming skewed
        int bfac = getHeight(root->left) - getHeight(root->right);

        //L to R rotation
        if (bfac > 1 && root->left->value < value) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        //R to R rotation
        else if (bfac > 1 && root->left->value > value) {
            return rightRotate(root);
        }
        //L to L rotation
        else if (bfac < -1 && root->right->value < value) {
            return leftRotate(root);
        }
            
        //R to L rotation
        else if (bfac < -1 && root->right->value > value) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    //Rotate functions to prevent a skewed tree
    Node* leftRotate(Node* root) {
        Node* x = root->right;
        Node* t = x->left;

        root->right = t;
        x->left = root;

        //Update the height
        x = updateHeight(x);
        root = updateHeight(root);

        return x;
    }

    Node* rightRotate(Node* root) {
        Node* x = root->left;
        Node* t = x->right;

        root->left = t;
        x->right = root;

        //Update the height
        root = updateHeight(root);
        x = updateHeight(x);

        return x;
    }

    //Function to write to file breadth first
    void printBFS(Node* root) {
        //Open file
        ofstream rFile;
        rFile.open("output-q1a2.txt");

        //Return if tree has no elements  
        if (root == NULL) {
            return;
        }
        //Create a queue to store memory location of tree elements. lineC counts which level the tree is on
        queue<Node*> nMem;
        int lineC = 0;

        //Initialise the height and enqueue the root element
        nMem.push(root);

        while (nMem.empty() == false) {
            //nCount counts how many elements at the current level 
            int nCount = nMem.size();
            rFile << lineC << ": ";
            cout << lineC << ": ";
            //Dequeue all nodes of current level and Enqueue all nodes of next level  
            while (nCount > 0) {
                Node* node = nMem.front();
                rFile << node->value << " ";
                cout << node->value << " ";
                nMem.pop();
                if (node->left != NULL)
                    nMem.push(node->left);
                if (node->right != NULL)
                    nMem.push(node->right);
                nCount--; 
            }
            lineC++;
            rFile << endl;
            cout << endl;
        }
        rFile.close();
    }

};