#include <fstream>
#include "heap.h"

void LoadDataFromFile(const char* filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Sorry: Could not open file " << filename << ".\n";
        return;
    }

    int number;
    while (file >> number) {
        InsertData(number);

        if (IsHeapFull()) {
            std::cout << "Error: Heap is full.\n";
            break;
        }
    }

    std::cout << "Data loaded from file " << filename << ".\n";
    file.close();
}

void HeapSort(){
    int sort_salaries[MAX_SIZE_HEAP];
    int original_size = size;

    // Copy the heap into an array, searching for the minimum value, and removing it to put it in the array
    for (int i = 0; i < original_size; i++) {
        sort_salaries[i] = RemoveMin();
    }

    std::cout << "\nSalarios ordenados (descendente):\n";
    for (int i = 0; i < original_size; i++) {
        std::cout << sort_salaries[i] << "\n";
    }
}


int main(void) {
    LoadDataFromFile("prueba.txt");

    int option = 0;
    while (option != 2) {
        std::cout << "\nMENU\n";
        std::cout << "1. Ordenar salarios\n";
        std::cout << "2. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            HeapSort();
            break;
        case 2:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida\n";
        }
    }

    return 0;
}