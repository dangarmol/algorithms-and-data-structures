//Grupo TAIS14
//Juan Alberto Camino Saez
//Daniel Garcia Molero

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Matriz.h"

using namespace std;

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(size_t N) : size(N), _count(size), id(size, -1), max(0){}

	// devuelve el número de conjuntos disjuntos
	size_t count() const { return _count; }

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = int(buscar(id[p]));
	}

	size_t maximo() {
		return max;
	}

	// unir los conjuntos que contengan a p y q
	void unir(size_t p, size_t q) {
		size_t tam;
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) {
			if (0 - id[i] > max) {
				max = 0 - id[i];
			}
			return;
		}
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
			tam = id[i];
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			tam = id[j];
		}
		_count--;

		if (0 - tam > max) {
			max = 0 - tam;
		}
	}

	// muestra el array por la salida o 
	void print(std::ostream& o = std::cout) const {
		o << _count << ": ";
		for (auto i = 0; i < size; ++i)
			o << id[i] << " ";
	}

protected:
	size_t size;             // los elementos son 0 .. size-1
	size_t _count;           // número de conjuntos disjuntos
	size_t max;
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i
	mutable std::vector<int> tamanio;

};

inline std::ostream& operator<<(std::ostream & o, ConjuntosDisjuntos const& a) {
	a.print(o);
	return o;
}

void comprobarAlrededorInicial(const Matriz<size_t> &mapa, ConjuntosDisjuntos &c, int i, int j, int x, int y) {
	for (int k = i - 1; k <= i; ++k) {
		for (int l = j - 1; l <= j + 1; ++l) {
			if (k >= 0 && k < x && l >= 0 && l < y) {
				if (mapa[k][l] == 1) {
					c.unir(i * y + j, k * y + l);
				}
			}
			if (k == i && l >= j) {
				return;
			}
		}
	}
}

void comprobarAlrededor(const Matriz<size_t> &mapa, ConjuntosDisjuntos &c, int i, int j, int x, int y) {
	for (int k = i - 1; k <= i + 1; ++k) {
		for (int l = j - 1; l <= j + 1; ++l) {
			if (k >= 0 && k < x && l >= 0 && l < y) {
				if (mapa[k][l] == 1) {
					c.unir(i * y + j, k * y + l);
				}
			}
		}
	}
}

ConjuntosDisjuntos unirInicial(int x, int y, const Matriz<size_t> &mapa) {
	ConjuntosDisjuntos c(x * y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (mapa[i][j] == 1) {
				comprobarAlrededorInicial(mapa, c, i, j, x, y);
			}
		}
	}
	return c;
}

//El coste de la función es O(x * y), siendo x las filas e y las columnas del mapa, ya que leer la matriz tiene coste x * y, unir las manchas 
// (función unirInicial() ) tiene coste x * y, y por ultimo es coste lineal en m (numero de manchas nuevas), por lo que  el coste total
//está incluido en O(x * y)
bool resuelve() {
	char c;
	string linea;
	int x, y, m, m1, m2;
	cin >> x;
	if (!cin) return false;

	cin >> y;
	cin.ignore();
	Matriz<size_t> mapa = Matriz<size_t>(x, y, 0);
	for (int i = 0; i < x; ++i) {
		getline(cin, linea);
		for (int j = 0; j < y; ++j) {
			if (linea[j] == '#') mapa[i][j] = 1;
		}
	}
	ConjuntosDisjuntos conj = unirInicial(x, y, mapa);
	cin >> m;
	cout << conj.maximo();
	if (m != 0) {
		cout << " ";
	}
	for (int i = 0; i < m; ++i) {
		cin >> m1 >> m2;
		mapa[m1 - 1][m2 - 1] = 1;
		comprobarAlrededor(mapa, conj, m1 - 1, m2 - 1, x, y);
		cout << conj.maximo();
		if (i != m - 1) {
			cout << " ";
		}
	}
	cout << endl;
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelve()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}