#include <fstream>
#include "heap.h"
#include "employee.h" 

void LoadDataFromFile(const char* filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Sorry: Could not open file " << filename << ".\n";
        return;
    }

    Employee empleado;
    int count = 0; 
    while (file >> empleado.nombre >> empleado.apellido >> empleado.salario >> empleado.cargo) {
        InsertData(empleado);
        count++;

        if (IsHeapFull()) {
            std::cout << "Error: Heap is full after " << count << " empleados.\n";
            break;
        }
    }

    std::cout << "Loaded " << count << " employees from file " << filename << ".\n";
    file.close();
}


int main(void) {
    LoadDataFromFile("usuarios.txt");

    int option = 0;
    while (option != 4) {
        std::cout << "\nMENU\n";
        std::cout << "1. Ordenar salarios\n";
        std::cout << "2. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            OrderHeap();
            break;
        case 3:
            
            break;
        case 4:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida\n";
        }
    }

    return 0;
}