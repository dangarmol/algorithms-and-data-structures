#include <iostream>
#include <cmath>
#include <algorithm>

#include "BinTree.h"

using namespace std;


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

int calcularAltura(const BinTree<char> &arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		int alturaIz, alturaDr;
		alturaIz = calcularAltura(arbol.left());
		alturaDr = calcularAltura(arbol.right());
		return max(alturaIz, alturaDr) + 1;
	}
}

void resuelve() {
	BinTree<char> arbol = leerArbol();
	int altura = calcularAltura(arbol);
	cout << altura << "\n";
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelve();
	}
	return 0;
}