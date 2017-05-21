#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

void parcialmenteOrdenado(int v[], int ini, int fin, int &vMin, int &vMax, bool &b)
{
	if (ini == fin)
	{
		b = true;
	}
	else if (fin - ini == 1)
	{
		if (v[ini] <= v[fin])
		{
			vMin = v[ini];
			vMax = v[fin];
			b = true;
		}
		else
		{
			vMin = v[fin];
			vMax = v[ini];
			b = false;
		}
	}
	else
	{
		int vMinIz, vMinDr, vMaxIz, vMaxDr;
		bool bIz, bDr;
		int m = (ini + fin) / 2;

		parcialmenteOrdenado(v, ini, m, vMinIz, vMaxIz, bIz);
		parcialmenteOrdenado(v, m + 1, fin, vMinDr, vMaxDr, bDr);

		vMin = min(vMinIz, vMinDr);
		vMax = max(vMaxIz, vMaxDr);

		b = bIz && bDr && vMinIz <= vMinDr && vMaxDr >= vMaxIz;
	}
}

bool parcialmenteOrdenado(int v[], int j)
{
	int vMin, vMax;
	bool b;
	parcialmenteOrdenado(v, 0, j - 1, vMin, vMax, b);
	return b;
}

bool resuelve()
{
	int v[100000];
	int j = 0;

	cin >> v[0];

	if (v[0] == 0)
		return false;

	do
	{
		j++;
		cin >> v[j];
	}
	while (v[j] != 0);

	if (parcialmenteOrdenado(v, j))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

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