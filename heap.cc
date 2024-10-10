#include "heap.h"

int heap[MAX_SIZE_HEAP]; 
int size = 0;   

/**
 * @Function Parent: Return the parent of a node
 * @Function LeftChild: Return the left child of a node
 * @Function RightChild: Return the right child of a node
 * @Function IsHeapFull: Check if the heap is full
 * @Function IsHeapEmpty: Check if the heap is empty
 */
int Parent(int i) { return (i - 1) / 2; }
int LeftChild(int i) { return 2 * i + 1; }
int RightChild(int i) { return 2 * i + 2; }
bool IsHeapFull() { return size == MAX_SIZE_HEAP; }
bool IsHeapEmpty() { return size == 0; }

/*
    @Function SiftDown: Sift up the data in the heap (Bubble up)
    @param data: Data to be sifted up
    @param i: Index of the data
    Move the element up the heap until the heap property is satisfied, that is when the parent is greater 
    than the child
*/
void SiftDown(int data, int i){
    if (i == 0) {
        heap[0] = data;
        return;
    }

    int parent = Parent(i);

    if (heap[parent] < data)
    {  
        heap[i] = heap[parent];
        SiftDown(data, parent); //2n/3 
    }
    else
    {   
        heap[i] = data;
    }
}

/*
    @Function SearchSmallestElement: Search the smallest element in the heap
    @param i: Index of the element
    @param _size: Size of the heap
    @return: The index of the smallest element
    Search the smallest element in the heap, comparing the left and right child with the current element
*/

int SearchLargestElement(int i, int _size){
    int left = LeftChild(i);
    int right = RightChild(i);
    int current_min = i;

    if(left < _size && heap[left] > heap[current_min]){
        current_min = left;
    }

    if(right < _size && heap[right] > heap[current_min]){
        current_min = right;
    }

    return current_min;
}

/*
    @Function InsertData: Insert data into the heap
    @param data: Data to be inserted
    Insert data into the heap and increase the size of the heap
*/
void InsertData(int data){
    heap[size] = data; 
    SiftDown(data, size); //O(log n)
    size++;
}

void HeapifyDown(int i, int _size){
 
    int current_max = SearchLargestElement(i, _size);

    if(current_max != i){
        int temp = heap[i];
        heap[i] = heap[current_max];
        heap[current_max] = temp;

        HeapifyDown(current_max, _size);
    }
}

/**
 * @Function RemoveMin: Remove the minimum value from the heap
 * Remove the minimum value from the heap and decrease the size of the heap
 * @return: The minimum value of the heap
*/

int RemoveMin(){
    if (IsHeapEmpty()) {
        std::cout << "Heap is empty.\n";
        return -1;
    }

    int minValue = heap[0]; 
    heap[0] = heap[size - 1];
    size--;
    HeapifyDown(0, size); //min para 

    return minValue; 
}


/**
 * @Function DisplayHeap: Display the content of the heap
 * Display the content of the heap
 */

void DisplayHeap(int arr[]){
    std::cout << "Contenido del heap:\n";
    for (int i = 0; i < size; i++) 
        std::cout << arr[i] << "\n"; 
}

