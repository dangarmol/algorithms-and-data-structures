#include <iostream>
#include <vector>

#include "TreeMap_AVL.h"

using namespace std;

//El coste es O(n log(n)), siendo n el numero de días que Andrés sigue la serie (número de entradas)
//Esto es porque para cada entrada se ejecuta funciones de coste logarítmico (búsqueda e inserción en el árbol)
int diasSinRepeticion(const vector<int> &v) {
	TreeMap <int, int> arbol;
	int numDias = 0, maximo = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (arbol.contains(v[i])) {
			int aux;
			if (maximo < numDias) {
				maximo = numDias;
			}
			aux = arbol.at(v[i]);
			if (i - aux <= numDias) {
				numDias = i - aux;
			}
			else {
				++numDias;
			}
			arbol.insert(v[i], i);
		}
		else {
			arbol.insert(v[i], i);
			++numDias;
		}
	}
	if (maximo < numDias) {
		maximo = numDias;
	}
	return maximo;
}

void resuelve() {
	vector <int> vector;
	int nDias, capitulo;

	cin >> nDias;
	for (int i = 0; i < nDias; ++i) {
		cin >> capitulo;
		vector.push_back(capitulo);
	}
	cout << diasSinRepeticion(vector) << endl;
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve();
	}
	return 0;
}