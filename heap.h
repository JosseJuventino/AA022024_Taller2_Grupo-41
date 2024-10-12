#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "employee.h"

#define MAX_SIZE_HEAP 1000

// @ var heap: Array that represents the heap
// @ var size: Actual size of the heap
extern Employee heap[MAX_SIZE_HEAP];
extern int size;


// Auxiliar functions
/*
    @Function Parent: Return the parent of a node
    @Finction LeftChild: Return the left child of a node    
    @Function RightChild: Return the right child of a node
    @Function IsHeapFull: Check if the heap is full
    @Function IsHeapEmpty: Check if the heap is empty
    @Function SiftDown: Sift down the data in the heap (Bubble down)
    @Function InsertData: Insert data into the heap
    @Function RemoveMin: Remove the minimum value from the heap
*/

int Parent(int i);
int LeftChild(int i);
int RightChild(int i);
bool IsHeapFull();
bool IsHeapEmpty();
void SiftDown(int i);
void InsertData(Employee data);  
Employee RemoveMin(); 
void OrderHeap();
int SearchHeap(float value);

#endif 
