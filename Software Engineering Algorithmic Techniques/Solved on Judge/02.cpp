#include <iostream>
#include <algorithm>
#include <fstream>

#include "BinTree.h"

using namespace std;

struct Solucion{
	int altura;
	bool avl;
	int raiz;
} ;

BinTree<int> leerArbol() {
	int raiz;
	std::cin >> raiz;
	if (raiz == -1) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

//El coste de esta función es O(n), siendo n el número de nodos del árbol
Solucion comprobarArbolAVL(const BinTree <int> &arbol, bool izquierdo) {
	Solucion sol;
	if (arbol.left().empty() && arbol.right().empty()) {
		sol.altura = 1;
		sol.avl = true;
		sol.raiz = arbol.root();
		return sol;
	}
	else {
		Solucion solIz, solDr;
		if (arbol.right().empty()) {
			solIz = comprobarArbolAVL(arbol.left(), true);
			sol.altura = solIz.altura + 1;
			if (solIz.altura <= 1 && arbol.root() > solIz.raiz) sol.avl = true;
			else sol.avl = false;
			if (izquierdo) sol.raiz = arbol.root();
			else sol.raiz = solIz.raiz;
			return sol;
		}
		else if (arbol.left().empty()) {
			solDr = comprobarArbolAVL(arbol.right(), false);
			sol.altura = solDr.altura + 1;
			if (solDr.altura <= 1 && arbol.root() < solDr.raiz) sol.avl = true;
			else sol.avl = false;
			if (izquierdo) sol.raiz = solDr.raiz;
			else sol.raiz = arbol.root();
			return sol;
		}
		else {
			solIz = comprobarArbolAVL(arbol.left(), true);
			solDr = comprobarArbolAVL(arbol.right(), false);
			sol.altura = max(solIz.altura, solDr.altura) + 1;
			sol.avl = false;
			if (solIz.avl && solDr.avl) {
				if (abs(solIz.altura - solDr.altura) <= 1) {
					if (arbol.root() > solIz.raiz && arbol.root() < solDr.raiz) {
						sol.avl = true;
					}
				}
			}
			if (izquierdo) sol.raiz = solDr.raiz;
			else sol.raiz = solIz.raiz;
			return sol;
		}
	}
}

bool comprobarArbol(const BinTree <int> &arbol) {
	return comprobarArbolAVL(arbol, true).avl;
}

void resuelve() {
	BinTree<int> arbol = leerArbol();

	if (!arbol.empty()) {
		if (comprobarArbol(arbol)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		cout << "SI" << endl;
	}
}

/*int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve();
	}
	return 0;
}*/

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelve();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
}