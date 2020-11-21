#pragma once
#include <iostream>
#include <vector>
#include<queue>
#include "Node.h"
#include <fstream>

using namespace std;

//Heap Class
class BinaryHeap {
private:
    vector <int> heap;
    //Returns left child of heap
    int left(int parent) {
        int l = 2 * parent + 1;
        if (l < heap.size())
            return l;
        else
            return -1;
    }

    //Returns right child of heap
    int right(int parent) {
        int r = 2 * parent + 2;
        if (r < heap.size())
            return r;
        else
            return -1;
    }

    //Finds the parent of the heap
    int parent(int child) {
        int p = (child - 1) / 2;
        if (child == 0)
            return -1;
        else
            return p;
    }

    void heapifyup(int index) {
        if (index >= 0 && parent(index) >= 0 && heap[parent(index)] > heap[index])
        {
            int temp = heap[index];
            heap[index] = heap[parent(index)];
            heap[parent(index)] = temp;
            heapifyup(parent(index));
        }
    }

public:
    BinaryHeap() {

    }

    //Function to insert elements into the heap
    void Insert(int element) {
        heap.push_back(element);
        heapifyup(heap.size() - 1);
    }

    //Returns the size of the heap
    int Size() {
        return heap.size();
    }

    //Loop through heap and print
    void printHeap() {
        size_t lNumber = 0; 
        size_t nItems = 1; 
        size_t pLevel = 0; 

        //Open file
        ofstream rFile2;
        rFile2.open("output-q2a2.txt");

        for (const auto& v : heap) 
        {
            if (pLevel == 0) 
                rFile2 << lNumber << ":";

            rFile2 << v << ' ';
            ++pLevel;

            //When level is completed double the width and insert on new line
            if (pLevel == nItems)
            {
                ++lNumber;
                nItems *= 2; 
                pLevel = 0;
                rFile2 << endl;
            }
        }
    }
};