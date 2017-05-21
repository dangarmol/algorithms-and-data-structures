#include <iostream>

using namespace std;

int numPares(int v[], int n)
{
	int pares = 0;

	for (int k = 0; k < n; k++)
		if (v[k] % 2 == 0)
			pares++;

	return pares;
}

void resuelve()
{
	int v[10000];
	int n = 0;
	cin >> n;

	for (int k = 0; k < n; k++)
		cin >> v[k];
	
	cout << numPares(v,n) << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}