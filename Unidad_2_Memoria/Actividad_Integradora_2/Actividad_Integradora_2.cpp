//Código problemático:
#include <iostream>
#include <string>

class Personaje {
public:
	std::string nombre;
	int estadisticas[3];
	Personaje(std::string n, int vida, int ataque, int defensa) {
		nombre = n;
		estadisticas[0] = vida;
		estadisticas[1] = ataque;
		estadisticas[2] = defensa;
		std::cout << "Constructor: nace " << nombre << std::endl;
	}
	void imprimir() {
		std::cout << "Personaje " << nombre << " [Vida: " << estadisticas[0] << ", ATK: " << estadisticas[1] << ", DEF: " << estadisticas[2] << "]" << std::endl;
	}
};

void simularEncuentro() {
	std::cout << "\n--- Iniciando encuentro ---" << std::endl;
	Personaje heroe("Aragorn", 100, 20, 15);
	heroe.imprimir();
	Personaje copiaHeroe = heroe;
	copiaHeroe.nombre = "Copia de Aragorn";
	copiaHeroe.imprimir();
	std::cout << "Saliendo del encuentro..." << std::endl;
}

int main() {
	simularEncuentro();
	std::cout << "\nSimulación terminada." << std::endl;
	return 0;
}