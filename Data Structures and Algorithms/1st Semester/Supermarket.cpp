#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
#include <vector>
using namespace std;

void calcularMejorCoste(vector<vector<int>> coste, vector<bool> m, vector<int> productosCogidos, int k, int p, int nProductos, int nSupermercados, int costeActual, int &mejorCoste)
{
	cout << k << endl;
	if (k < nProductos)
	{
		for (int i = 0; i < nSupermercados; i++)
		{
			costeActual += coste[i][k];
			productosCogidos[i] += 1;
			p += 1;

			if (productosCogidos[i] <= 3 && !m[k])
			{
				if (p == nProductos)
				{
					if (mejorCoste == -1 || mejorCoste > costeActual)
						mejorCoste = costeActual;
				}
				else
				{
					m[k] = true;
					calcularMejorCoste(coste, m, productosCogidos, k + 1, p, nProductos, nSupermercados, costeActual, mejorCoste);
					m[k] = false;
				}
			}

			costeActual -= coste[i][k];
			productosCogidos[i] -= 1;
			p -= 1;

			if (p == nProductos)
			{
				if (mejorCoste == -1 || mejorCoste > costeActual)
					mejorCoste = costeActual;
			}
			else
				calcularMejorCoste(coste, m, productosCogidos, k + 1, p, nProductos, nSupermercados, costeActual, mejorCoste);
		}
	}
}

void solve() {
	int numMarkets, numProducts, next, bestCost = -1;
	cin >> numMarkets >> numProducts;
	vector<vector<int>> matrix(numMarkets, vector<int>(numProducts));
	for (int i = 0; i < numMarkets; ++i) {
		for (int j = 0; j < numProducts; ++j) {
			cin >> next;
			matrix[i][j] = next;
		}
	}
	vector<bool> marked(20, false);
	vector<int> bought(numMarkets, 0);

	calcularMejorCoste(matrix, marked, bought, 0, 0, numProducts, numMarkets, 0, bestCost);

	if (bestCost == -1)
		cout << "Sin solucion factible" << endl;
	else
		cout << bestCost << endl;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; ++i) {
		solve();
	}
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
