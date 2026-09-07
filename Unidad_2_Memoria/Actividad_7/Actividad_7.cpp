#include <iostream>
using namespace std;
class Punto {
public:    int x;    int y;
      // Constructor
      Punto(int _x, int _y) : x(_x), y(_y) {
          cout << "Constructor: Punto(" << x << ", " << y << ") creado." << endl;
      }
      // Destructor
      ~Punto() {
          cout << "Destructor: Punto(" << x << ", " << y << ") destruido." << endl;
      }
      // Método para imprimir valores
      void imprimir() {
          cout << "Punto(" << x << ", " << y << ")" << endl;
      }
};
int main() {
    // Objeto en el stack
    Punto pStack(30, 40);
    pStack.imprimir();
    // Objeto en el heap
    Punto* pHeap = new Punto(50, 60);
    pHeap->imprimir();
    // Coloca breakpoints en la creación de pStack y pHeap
    // Inspecciona las direcciones de memoria de ambos objetos:
    // - pStack: dirección obtenida directamente.
    // - pHeap: la variable pHeap es un puntero que contiene la dirección del objeto en el heap.
    // Recuerda liberar la memoria del heap
    delete pHeap;
    return 0;
}