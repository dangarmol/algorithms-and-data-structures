#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "TreeMap_AVL.h"

using namespace std;

struct ClaveValor {
	const int n;
	int f;
};

void mostrar(TreeMap<string, TreeMap<int, int>> &arbol) {
	TreeMap<string, TreeMap<int, int>>::Iterator it = arbol.begin();
	TreeMap<string, TreeMap<int, int>>::Iterator itFin = arbol.end();

	while (it != itFin) {
		TreeMap<string, TreeMap<int, int>>::ClaveValor c = *it;
		TreeMap <int, int> aux = c.valor;

		cout << c.clave << " ";
		TreeMap<int, int>::Iterator it1 = aux.begin();
		TreeMap<int, int>::Iterator itFin1 = aux.end();

		while (it1 != itFin1) {
			TreeMap<int, int>::ClaveValor c1 = *it1;

			cout << c1.clave << " ";
			it1++;
		}
		cout << endl;
		it++;
	}

}

void resuelve(const int &n) {
	TreeMap<string, TreeMap<int, int>> arbol;
	string palabra;


	getline(cin, palabra);
	for (int i = 1; i <= n; ++i) {
		getline(cin, palabra);
		transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
		istringstream iss(palabra);
		while (iss) {
			string s;
			iss >> s;
			if (s.size() > 2) {
				if (!arbol[s].contains(i)) {
					arbol[s].insert(i, 0);
				}
			}
		}
	}
	mostrar(arbol);
	cout << "----" << '\n';
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

/*int main() {
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
}*/
