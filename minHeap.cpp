/*
 * Name: Elle Hanckel
 * Date Submitted: 04/19/2023
 * Assignment Name: Min-Heap Implementation Using a Vector
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "minHeap.h"

using namespace std;

void minHeap::siftUp(int pos){

    //getting parent index
    int parentIndex = (pos - 1)/ 2;

    //looping through heap until correct
    while ((pos > 0) && (heap[pos] < heap[parentIndex])) { //while index is greater than 0 and element at pos index is less that parent
        //swap elements
        swap(heap[pos], heap[parentIndex]); 
        //making new position to be parent index
        pos = parentIndex;
        //finding new parent index for new pos
        parentIndex = (parentIndex - 1)/2;
    } 
}

void minHeap::siftDown(int pos){

    //getting child indexs
    int leftIndex = pos * 2 + 1;
    int rightIndex = pos * 2 + 2;
    //temp variable 
    int biggerIndex = pos;

    //if left child index is less than size of heap and left child is less than element at biggerIndex
    if ((leftIndex < heap.size()) && (heap[leftIndex] < heap[biggerIndex])) {
        //make biggerIndex equal to left child index
        biggerIndex = leftIndex;
    //if right child index is less than size of heap and right child is less than element at biggerIndex
    } if ((rightIndex < heap.size()) && (heap[rightIndex] < heap[biggerIndex])) {
        //make biggerIndex equal to right child index
        biggerIndex = rightIndex;
    }

    //if pos is not equal to biggerIndex
    if (pos != biggerIndex) {
        //swap element at pos with biggerIndex
        swap(heap[pos], heap[biggerIndex]);
        //recursively call siftDown()
        siftDown(biggerIndex);
    }

}


//Implement all the following functions
minHeap::minHeap(vector<int> data){ //Should build the heap from bottom-up

    //pushing data into heap vector
    for (int i = 0; i < data.size(); i++) {
        heap.push_back(data[i]);
    }    

    //calling siftDown to build heap from bottom-up
    for (int i = heap.size() - 1;  i >= 0; i--) {
        siftDown(i);
    }

} 

void minHeap::insert(int value){ //Insert value into heap
    //pushing element to back of heap
    heap.push_back(value);
    //calling siftUp until element is in right index
    siftUp((heap.size()-1));
} 

int minHeap::removeMin(){ //Removes minimum value
    
    //base case, if heap is empty, return 0
    if (heap.size() == 0) {
        return -1;
    }

    //getting size of heap
    int size = heap.size() - 1;
    //temp variable for min value
    int temp = heap[0];
    
    //swapping min value with last value in heap
    swap(heap[0], heap[size]);
    //deleting min value from heap
    heap.pop_back();

    //ordering the heap 
    siftDown(0);

    //returning min value
    return temp;

}