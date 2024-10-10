#include <iostream>
#include <fstream>

#define MAX_SIZE_HEAP 1000

/*
    @var heap: Array that represents the heap
    @var size: Actual size of the heap  
*/

int heap[MAX_SIZE_HEAP];
int size = 0;

/*
 Auxiliar functions
    @Function Parent: Return the parent of a node
*/

int Parent(int i) { return (i - 1) / 2; } //O(1)
bool IsHeapFull() {return size == MAX_SIZE_HEAP; } //O(1)
int LeftChild(int i) { return 2 * i + 1; } //O(1)
int RightChild(int i) { return 2 * i + 2; } //O(1)

/*
 @Function DisplayHeap: Display the content of the heap
*/
void DisplayHeap() {
    std::cout << "Contenido del heap:" << std::endl;
    for (int i = 0; i < size; i++) 
        std::cout << heap[i] << "\n"; 
}

/*
    @Function SiftUp: Sift up the data in the heap (Bubble up)
    @param data: Data to be sifted up
    @param i: Index of the data
    Move the element up the heap until the heap property is satisfied, that is when the parent is greater 
    than the child
*/

void SiftUp(int data, int i){
    if (i == 0) {
        heap[0] = data;
        return;
    }

    int parent = Parent(i);

    if (heap[parent] > data)
    {  
        heap[i] = heap[parent];
        SiftUp(data, parent); //2n/3 
    }
    else
    {   
        heap[i] = data;
    }
}

/*
    @Function InsertData: Insert data into the heap
    @param data: Data to be inserted
    Insert data into the heap and increase the size of the heap
*/
void InsertData(int data){
    heap[size] = data;
    SiftUp(data, size); //O(log n)
    size++;
}

/*
    @Function LoadDataFromFile: Load data from a file
    @param filename: Name of the file to be loaded
    Load data from a file and insert it into the heap
*/
void LoadDataFromFile(const char* filename){
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Sorry: Could not open file " << filename << std::endl;
        return;
    }

    int number;

    while (file >> number)
    {
        InsertData(number);

        if(IsHeapFull()){
            std::cerr << "Sorry: Heap is full" << std::endl;
            break;
        }
    }

    std::cout << "Data loaded from file " << filename << "." << std::endl;
    file.close();
}

/*
    @Function InsertNewData: Insert new data into the heap
    Ask the user for a new data and insert it into the heap
*/

void InsertNewData(){
    if(IsHeapFull()){
        std::cerr << "Sorry: Heap is full" << std::endl;
        return;
    }else{
        int data;
        std::cout << "Enter new data: ";
        std::cin >> data;
        InsertData(data);
    }
}


/*
    @Function HeapifyDown: Heapify the heap from the root
    @param i: Index of the root
    @param _size: Size of the heap
    Heapify the heap from the root to the end of the heap
*/
void HeapifyDown(int i, int _size){
    int left = LeftChild(i);
    int right = RightChild(i);
    int current_min = i;

    if(left < _size && heap[left] < heap[current_min]){
        current_min = left;
    }

    if(right < _size && heap[right] < heap[current_min]){
        current_min = right;
    }

    if(current_min != i){
        int temp = heap[i];
        heap[i] = heap[current_min];
        heap[current_min] = temp;

        HeapifyDown(current_min, _size);
    }
}

/*
    @Function HeapSort: Sort the heap
    Sort the heap using the heap sort algorithm
*/

void HeapSort(){

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        //0 is the root of the heap
        //i is the size of the heap (decreasing)
        HeapifyDown(0, i);
    }
}

int main(void){
    LoadDataFromFile("prueba.txt");
    int option = 0;
    while (option != 4)
    {
        std::cout << "1. Insert new salary" << std::endl;
        std::cout << "2. Show salary" << std::endl;
        std::cout << "3. Sort salary" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            InsertNewData();
            break;
        case 2:
            DisplayHeap();
            break;
        case 3:
            HeapSort();
            break;
        case 4:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }
    }

    return 0;
}