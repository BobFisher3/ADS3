#include <iostream>
#include <fstream>
#include<queue>
#include "AVL.h"
#include "Node.h"

using namespace std;

int main()
{
    //Open File One
    ifstream file;
    file.open("input-q1a2.txt");

    int inputData, size;
    int counter = 0;

    AVL avl;
    Node* root = nullptr;

    if (!file) {
        cout << "There was an error opening the file." << endl;
        return 0;
    }
    file >> size;
    while (file >> inputData) {
        //if (inputData != size) {
            root = avl.insert(root, inputData);
            counter++;
       // }
    }

    if (counter != size) {
        cout << "Unexpected list size." << endl;
        return 0;
    }

    file.close();
   // avl.printBFS(root);
    avl.printBFS(root);

    return 0;
}