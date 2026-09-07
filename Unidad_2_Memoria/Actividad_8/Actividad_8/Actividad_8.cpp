#include <iostream>
#include <string>
using namespace std;
class Punto {
public: 
	  string name;
	  int x;
	  int y;
	  // Constructor
	  Punto(string _name, int _x, int _y) : name(_name), x(_x), y(_y) {
		  cout << "Constructor: Punto " << name << " (" << x << ", " << y << ") creado." << endl;
	  }
	  // Destructor
	  ~Punto() {
		  cout << "Destructor: Punto " << name << "(" << x << ", " << y << ") destruido." << endl;
	  }
	  // Método para imprimir valores
	  void imprimir() {
		  cout << "Punto " << name << "(" << x << ", " << y << ")" << endl;
	  }
};

void cambiarNombre(Punto p, string nuevoNombre) {
	p.name = "nuevoNombre";
}

int main() {    // Objeto original
	Punto original("original", 70, 80);
	original.imprimir();
	cambiarNombre(original, "cambiado");
	original.imprimir();
	return 0;
}