#include <iostream>
#include <algorithm>

#include "BinTree.h"

using namespace std;

struct Solucion{
	int altura;
	bool equilibrado;
} ;

BinTree<char> leerArbol() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.') { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

Solucion comprobarArbol(const BinTree <char> &arbol) {
	Solucion sol;
	if (arbol.empty()) {
		sol.altura = 0;
		sol.equilibrado = true;
		return sol;
	}
	else {
		Solucion solIz, solDr;
		solIz = comprobarArbol(arbol.left());
		solDr = comprobarArbol(arbol.right());
		if (solIz.equilibrado && solDr.equilibrado) {
			if (abs(solIz.altura - solDr.altura) <= 1) {
				sol.altura = max(solIz.altura, solDr.altura) + 1;
				sol.equilibrado = true;
				return sol;
			}
		}
		sol.equilibrado = false;
		return sol;
	}
}

void resuelve() {
	BinTree<char> arbol = leerArbol();

	if (comprobarArbol(arbol).equilibrado) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve();
	}
	return 0;
}