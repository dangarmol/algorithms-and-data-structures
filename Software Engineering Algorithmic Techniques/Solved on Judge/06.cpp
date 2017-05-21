#include <iostream>
#include <string>
#include <fstream>

#include "PriorityQueue.h"

using namespace std;

class Paciente {
private:
	string nombre;
	int prioridad;
	int turno;

public:
	Paciente() {}

	Paciente(string nombre1, int prioridad1, int turno1) {
		nombre = nombre1;
		prioridad = prioridad1;
		turno = turno1;
	}

	string getNombre() const {
		return nombre;
	}

	int getPrioridad() const {
		return prioridad;
	}

	int getTurno() const {
		return turno;
	}

	bool operator< (const Paciente &paciente) const {
		if (prioridad < paciente.getPrioridad()) {
			return true;
		}
		else if (prioridad == paciente.getPrioridad()) {
			return turno < paciente.getTurno();
		}
		return false;
	}
};

void resuelve(const int &n) {
	PriorityQueue <Paciente> cola;
	Paciente paciente;
	string nombre;
	int prioridad;
	char operacion;

	for (int i = 0; i < n; ++i) {
		cin >> operacion;
		if (operacion == 'I') {
			cin >> nombre;
			cin >> prioridad;
			paciente = Paciente(nombre, 0 - prioridad, i);
			cola.push(paciente);
		}
		else {
			if (!cola.empty()) {
				paciente = cola.top();
				cola.pop();
				cout << paciente.getNombre() << '\n';
			}
		}
	}
	cout << "----" << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	while (numCasos != 0) {
		resuelve(numCasos);
		std::cin >> numCasos;
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}