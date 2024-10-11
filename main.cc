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
    int count = 0;  // Contador para verificar cuántos empleados se están cargando
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


void HeapSort() {
    Employee sorted_employees[MAX_SIZE_HEAP];
    int original_size = size;

    for (int i = 0; i < original_size; i++) {
        sorted_employees[i] = RemoveMin();
    }

    std::cout << "\nEmpleados ordenados por salario (descendente):\n";
    for (int i = 0; i < original_size; i++) {
        std::cout << sorted_employees[i].nombre <<  " - " << sorted_employees[i].salario << " - " << sorted_employees[i].cargo << "\n";
    }
}


int main(void) {
    LoadDataFromFile("usuarios.txt");

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