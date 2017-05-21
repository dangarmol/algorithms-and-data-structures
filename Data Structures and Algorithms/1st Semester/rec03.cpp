#include <iostream>
#include <math.h>

using namespace std;

int ingresos(int v[], int n, int dia, int e, int acu)
{
	if (n / 2 == dia)
		return acu;
	else
		ingresos(v, n, dia + 1, e * 2, acu + (v[dia] * e) + (v[n - dia - 1] * e));
}

int ingresos(int v[], int n)
{
	return ingresos(v, n, 0, 1, 0);
}

void resuelve()
{
	int n;
	int v[30];
	cin >> n;

	for (int k = 0; k < n; k++)
		cin >> v[k];
	
	cout << ingresos(v, n) << endl;
}

int main()
{
	int nCasos = 0;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}