#include <iostream>
using namespace std;
int main() {    // Tamaño del arreglo dinámico
    int tam = 5;
    // Asignar memoria en el Heap para un arreglo de enteros
    int* arrayHeap = new int[tam];
    // Inicializar y mostrar los valores y direcciones de memoria
    for (int i = 0; i < tam; i++) {
        arrayHeap[i] = (i + 1) * 10;
        cout << "arrayHeap[" << i << "] = " << arrayHeap[i] << " en dirección " << (arrayHeap + i) << endl;
    }
    // Liberar la memoria asignada en el Heap
    delete[] arrayHeap;
    arrayHeap = nullptr; // <- Uso correcto para evitar futuros errores
    /**********************************************************
    EXPERIMENTO 6
    ***********************************************************/
    cout << arrayHeap[0] << endl;

    /********************************************************/
    return 0;
}