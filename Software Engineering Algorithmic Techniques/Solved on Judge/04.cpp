#include <iostream>
#include <vector>

#include "TreeMap_AVL.h"

using namespace std;

//El coste es O(n log(n)), siendo n el numero de d�as que Andr�s sigue la serie (n�mero de entradas)
//Esto es porque para cada entrada se ejecuta funciones de coste logar�tmico (b�squeda e inserci�n en el �rbol)
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