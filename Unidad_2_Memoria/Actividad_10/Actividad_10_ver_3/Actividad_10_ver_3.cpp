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
	{
		cout << "Inicio del bloque" << endl;
		Punto pBloque(100, 200);
		// Coloca un breakpoint aquí para ver 'pBloque' en el stack.
		pBloque.imprimir();
	}
	Punto* pBloque2 = nullptr;
	{
		cout << "Inicio del bloque 2" << endl;
		pBloque2 = new Punto(500, 600);
		pBloque2->imprimir();
	}
	pBloque2->imprimir();
	delete pBloque2;
	return 0;
}