#include <iostream>
#include <string>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

bool esValida(int sol[], int k)
{
	int i = 0;
	while (i < k && sol[i] != sol[k]) i++;
	return i == k;
}

bool esSolucion(int k, int n)
{
	return k == (n - 1);
}

void tratarSolucion(int sol[], int v[][20], int &valorMinimo, int n)
{
	int aux = 0;

	for (int i = 0; i < n; i++)
		aux += v[i][sol[i]];

	if (valorMinimo == -1 || aux < valorMinimo)
		valorMinimo = aux;
}

void anagramas(int sol[], int v[][20], int &valorMinimo, int k, int n)
{
	for (int offset = 0; offset < n; offset++)
	{
		sol[k] = offset;

		if (esValida(sol, k))
		{
			if (esSolucion(k, n))
				tratarSolucion(sol, v, valorMinimo, n);
			else
				anagramas(sol, v, valorMinimo, k + 1, n);
		}
	}
}

bool resuelve()
{

	int funcionarios;

	cin >> funcionarios;

	if (funcionarios == 0)
		return false;

	int sol[20], trabajo[20][20], valorMinimo = -1;

	for (int i = 0; i < funcionarios; i++)
		for (int j = 0; j < funcionarios; j++)
			cin >> trabajo[i][j];

	anagramas(sol, trabajo, valorMinimo, 0, funcionarios);

	cout << valorMinimo << endl;

	return true;
}

int main()
{
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelve());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}