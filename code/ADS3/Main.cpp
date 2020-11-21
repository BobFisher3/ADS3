#include <iostream>
#include <fstream>
#include<queue>
#include <vector>
#include "AVL.h"
#include "Node.h"
#include "BinaryHeap.h"

using namespace std;

int main() {
    //QUESTION ONE
    //Open read file
    ifstream file;
    file.open("input-q1a2.txt");

    int inputData, size;
    int counter = 0;

    AVL avl;
    //Initialize root
    Node* root = nullptr;

    //Error handling
    if (!file) {
        cout << "There was an error opening the file." << endl;
        return 0;
    }

    //Write first line to size variable
    file >> size;
    //While data left in file, add elements to tree and increase counter to check size
    while (file >> inputData) {
            root = avl.insert(root, inputData);
            counter++;
    }

    //If the size of the tree does not match expected input, error
    if (counter != size) {
        cout << "Unexpected list size." << endl;
        return 0;
    }

    file.close();
    //Write the tree to file
    avl.printBFS(root);

    //QUESTION TWO
    BinaryHeap heap;
    int inputDataQ2;
    vector<int> inputVectorQ2;
    //Open file
    ifstream fileQ2("input-q2a2.txt");

    //Error Handling
    if (!fileQ2) {
        cout << "There was an error opening the file." << endl;
        return 0;
    }
    //Fail if string is given instead of int
    if (fileQ2.fail()) {
        cout << "invalid data type" << endl;
        return 0;
    }

    //Store file in vector
    int checkSize;
    fileQ2 >> checkSize;

    //Fill vector with file data
    while (fileQ2 >> inputDataQ2) {
        inputVectorQ2.push_back(inputDataQ2);
    }
    fileQ2.close();

    //Error checking
    if (inputVectorQ2.size() != checkSize) {
        cout << "List size does not match expected input" << endl;
        return 0;
    }
    for (int a = 0; a < checkSize; a++) {
        heap.Insert(inputVectorQ2[a]);
    }
    heap.printHeap();

    return 0;
}