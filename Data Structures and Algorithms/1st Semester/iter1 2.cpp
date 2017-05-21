#include <iostream>

using namespace std;

void getMax(int v[], int solucion[], int n)
{
	solucion[0] = v[0];
	solucion[1] = 1;

	for (int k = 1; k < n; k++)
	{
		if (solucion[0] == v[k])
			solucion[1]++;
		else if (solucion[0] < v[k])
		{
			solucion[0] = v[k];
			solucion[1] = 1;
		}
	}
}

void resuelve()
{
	int v[10000];
	int solucion[2];
	int n = 0;
	cin >> n;

	for (int k = 0; k < n; k++)
		cin >> v[k];

	getMax(v,solucion,n);
	cout << solucion[0] << " " << solucion[1] << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}