#include <iostream>
#include <vector>

#include "IndexPQ.h"

using namespace std;

class Par {
private:
	int id;
	int tiempo;
	int contador;

public:

	Par() {
		Par(0, 0);
	}

	Par(int id1, int tiempo1) {
		id = id1;
		tiempo = tiempo1;
		contador = 1;
	}

	Par(int id1, int tiempo1, int contador1) {
		id = id1;
		tiempo = tiempo1;
		contador = contador1;
	}

	bool operator<(const Par &par) const {
		if (tiempo < par.getTiempo()) {
			return true;
		}
		else if (tiempo == par.getTiempo()) {
			return id < par.getId();
		}
		return false;
	}

	int getId() const{
		return id;
	}

	int getTiempo() const {
		return tiempo;
	}

	int getContador() const {
		return contador;
	}
};

void mostrar(const int &id) {
	cout << id << endl;
}

//El coste de esta funcion es O(k * log(n)), debido a que tiene que dar k vueltas para sacar los ids mas prioritarios, y en cada vuelta se llama
//al update de la cola prioritaria, que debe recolocar la cola en caso de que la prioridad cambie y por ello tiene O(log(n)), siendo
//n el número de elementos que tiene la cola
void calcularTiempos(IndexPQ<Par> &cola, const int &k) {
	for (int i = 0; i < k; i++) {
		Par par1, par2;
		par1 = cola.top().prioridad;
		mostrar(par1.getId());
		par2 = Par(par1.getId(), par1.getTiempo() + (par1.getTiempo() / par1.getContador()), par1.getContador() + 1);
		cola.update(cola.top().elem, par2);
	}
}

void resuelve(const int &n) {
	int k;
	IndexPQ<Par> cola(n);
	for (size_t i = 0; i < n; ++i) {
		int id, tiempo;
		cin >> id;
		cin >> tiempo;
		Par par(id, tiempo);
		cola.push(i, par);
	}
	cin >> k;
	calcularTiempos(cola, k);
	cout << "----" << endl;
}

int main() {
	int n;

	cin >> n;
	while (n != 0) {
		resuelve(n);
		cin >> n;
	}
	return 0;
}