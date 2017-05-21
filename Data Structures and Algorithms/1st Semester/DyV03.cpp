#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

int buscarLetra(int v[], int ini, int fin, int nCajero, int &p)
{
	if (fin == 0)
	{
		return 0;
	}
	else if (fin - ini == 1)
	{
		int encontrado = 0;

		if (p == -1)
		{
			if (v[ini] <= nCajero && v[fin] > nCajero)
				p = fin;
		}

		if(p != -1)
		{
			int aux = p + nCajero;
			if (v[ini] == aux || v[fin] == aux)
				encontrado = aux;
		}

		return encontrado;
	}
	else
	{
		int encontradoIz, encontradoDr;
		int m = (ini + fin) / 2;

		encontradoIz = buscarLetra(v, ini, m, nCajero, p);
		if (encontradoIz == 0)
			encontradoDr = buscarLetra(v, m, fin, nCajero, p);

		return max(encontradoIz, encontradoDr);
	}
}

void resuelve()
{
	int nCantidad, nCajero, encontrado, p = -1;
	int v[100000];

	cin >> nCantidad >> nCajero;

	for (int k = 0; k < nCantidad; k++)
		cin >> v[k];

	encontrado = buscarLetra(v, 0, nCantidad - 1, nCajero, p);

	if (encontrado == 0)
		cout << "NO" << endl;
	else
		cout << encontrado << endl;
}

int main()
{
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}