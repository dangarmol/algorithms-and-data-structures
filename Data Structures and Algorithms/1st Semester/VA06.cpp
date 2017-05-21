#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

void calcularMejorCoste(int coste[][20], int productosCogidos[], int k, int nProductos, int nSupermercados, int costeActual, int &mejorCoste)
{
	for (int i = 0; i < nSupermercados; i++)
	{
		if (productosCogidos[i] < 3)
		{
			costeActual += coste[i][k];
			productosCogidos[i] += 1;

			if ((mejorCoste == -1 || mejorCoste > costeActual))
			{
				if (k == (nProductos - 1))
				{
					mejorCoste = costeActual;
				}
				else
				{
					calcularMejorCoste(coste, productosCogidos, k + 1, nProductos, nSupermercados, costeActual, mejorCoste);
				}
			}

			costeActual -= coste[i][k];
			productosCogidos[i] -= 1;
		}
	}
}

void resuelve() 
{
	int coste[20][20], productosCogidos[20] = {0}, nProductos, nSupermercados, mejorCoste = -1;

	cin >> nSupermercados >> nProductos;

	for (int i = 0; i < nSupermercados; ++i)
	{
		for (int j = 0; j < nProductos; ++j)
		{
			cin >> coste[i][j];
		}
	}

	calcularMejorCoste(coste, productosCogidos, 0, nProductos, nSupermercados, 0, mejorCoste);

	if (mejorCoste == -1)
		cout << "Sin solucion factible" << endl;
	else
		cout << mejorCoste << endl;
}

int main() 
{
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; ++i)
		resuelve();
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
