#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

bool esValida(char solucion[], int m[], int k)
{
	int a = 0, b = 0;

	for (int i = 0; i <= k; i++)
	{
		if (solucion[i] == 'C')
			a++;
		else
			b++;
	}

	return a <= m[0] && b <= m[1];
}

bool esSolucion(int k, int n)
{
	return k == (n - 1);
}

void tratarSolucion(char solucion[], int n)
{
	for (int i = 0; i < n; i++)
		cout << solucion[i];
	cout << " ";
}

void anagramas(char sol[], char v[], int m[],  int k, int n)
{
	for (int offset = 0; offset < 2; offset++)
	{
		sol[k] = v[offset];

		if (esValida(sol, m, k))
		{
			if (esSolucion(k, n))
				tratarSolucion(sol, n);
			else
				anagramas(sol, v, m, k + 1, n);
		}
	}
}

void resuelve()
{
	char a[1000];
	char v[2] = {'C', 'V'};
	int m[2] = {0, 0};

	cin >> m[0] >> m[1];
	anagramas(a, v, m, 0, m[0] + m[1]);
	cout << endl;
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