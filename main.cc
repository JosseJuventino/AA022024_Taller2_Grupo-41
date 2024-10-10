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

    if (heap[parent] < data)
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
    SiftUp(data, size);
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

        if (size == MAX_SIZE_HEAP)
        {
            std::cerr << "Sorry: Heap is full" << std::endl;
            break;
        }    
    }

    std::cout << "Data loaded from file " << filename << "." << std::endl;
    file.close();
}

int main(void){
    LoadDataFromFile("prueba.txt");
    DisplayHeap();
    return 0;
}