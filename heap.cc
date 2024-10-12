#include "heap.h"
#include "employee.h"

Employee heap[MAX_SIZE_HEAP]; 
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
void SiftDown(Employee data, int i) {
    if (i == 0) {
        heap[0] = data;
        return;
    }

    int parent = Parent(i);

    if (heap[parent].salario < data.salario) {
        heap[i] = heap[parent];
        SiftDown(data, parent);
    } else {
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

int SearchLargestElement(int i, int _size) {
    int left = LeftChild(i);
    int right = RightChild(i);
    int current_max = i;

    if (left < _size && heap[left].salario > heap[current_max].salario) {
        current_max = left;
    }

    if (right < _size && heap[right].salario > heap[current_max].salario) {
        current_max = right;
    }

    return current_max;
}

/*
    @Function InsertData: Insert data into the heap
    @param data: Data to be inserted
    Insert data into the heap and increase the size of the heap
*/
void InsertData(Employee data) {
    if (IsHeapFull()) {
        std::cerr << "Heap is full\n";
        return;
    }

    heap[size] = data;
    SiftDown(data, size);
    size++;
}

/*
    @Function HeapifyDown: Heapify the heap from the root
    @param i: Index of the element
    @param _size: Size of the heap
    Heapify the heap from the root, comparing the current element with the left and right child
*/

void HeapifyDown(int i, int _size) {
    int current_max = SearchLargestElement(i, _size);

    if (current_max != i) {
        Employee temp = heap[i];
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

Employee RemoveMin() {
    if (IsHeapEmpty()) {
        std::cerr << "Heap is empty\n";

        Employee emptyEmployee;
        emptyEmployee.salario = -1;  
        return emptyEmployee;
    }

    Employee EmployeeMin = heap[0];
    heap[0] = heap[size - 1];
    size--;
    HeapifyDown(0, size);

    return EmployeeMin;  
}

/**
 * @Function DisplayHeap: Display the content of the heap
 * Display the content of the heap
 */

void DisplayHeap(){
    std::cout << "Contenido del heap:" << std::endl;
    for (int i = 0; i < size; i++) 
        std::cout << heap[i].salario << "\n"; 
}

/*
    @Function OrderHeap: Order the heap
    Order the heap by removing the minimum value from the heap, ordering in descending order
*/
void OrderHeap() {
    Employee sorted_employees[MAX_SIZE_HEAP];
    int original_size = size;

    for (int i = 0; i < original_size; i++) {
        sorted_employees[i] = RemoveMin();
        std::cout << sorted_employees[i].nombre <<  " - " << sorted_employees[i].salario << " - " << sorted_employees[i].cargo << "\n";
    }
}


/*
    @Function SearchHeap: Search for an element in the heap and return its original index
    @param value: Value to search for (salary in this case)
    @return: Index of the element in the original heap, or -1 if not found
*/
int SearchHeap(float value) {
    for (int i = 0; i < size; ++i) {
        if (heap[i].salario == value) {
            return i;
        }
    }
    return -1;
}
