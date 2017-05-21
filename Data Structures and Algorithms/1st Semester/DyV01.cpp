#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>

using namespace std;

char buscarLetra(char v[], int i, int n)
{
	if (n - i == 1)
	{
		if (v[n] - v[i] > 1)
			return v[i] + 1;
		else
			return 0;
	}
	else
	{
		char solDer, solIzq;

		if (v[(n + i) / 2] - v[i] != (n - i) / 2)
			solIzq = buscarLetra(v, i, (i + n) / 2);
		else
			solDer = buscarLetra(v, (i + n) / 2, n);

		return max(solIzq, solDer);
	}
}

char buscarLetra(char v[], int n)
{
	return buscarLetra(v, 0, n);
}

void resuelve()
{
	char v[100];
	char a, b;
	int n;

	cin >> a >> b;

	n = b - a - 1;
	for (int k = 0; k <= n; k++)
		cin >> v[k];

	if (v[0] != a)
		cout << a << endl;
	else if (v[n] != b)
		cout << b << endl;
	else
		cout << buscarLetra(v, n) << endl;	
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
		
	return 0;
}