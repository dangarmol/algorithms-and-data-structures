#include <iostream>

using namespace std;

int ingresosFinal(int v[], int n, int i, int j, int elevar, int acu)
{
	if (j == n / 2)
		return  (v[j] * elevar) + v[i] * elevar + acu;
	else
		return ingresosFinal(v, n, i + 1, j - 1, elevar * 2, acu + (v[i] * elevar) + (v[j] * elevar));
}

int ingresosNoFinal(int v[], int n, int i, int j, int elevar)
{
	if (j == n / 2)
		return  (v[j] * elevar) + v[i] * elevar;
	else
		return (v[i] * elevar) + (v[j] * elevar) + ingresosNoFinal(v, n, i + 1, j - 1, elevar * 2);
}

int ingresos(int v[], int n)
{
	//return ingresosNoFinal(v, n, 0, n-1, 1);
	return ingresosFinal(v, n, 0, n - 1, 1, 0);
}

void resolver()
{
	int v[30];
	int nElems;
	cin >> nElems;

	if (nElems > 0)
	{
		for (int k = 0; k < nElems; k++)
			cin >> v[k];

		cout << ingresos(v, nElems) << endl;
	}
	else
		cout << "0" << endl;
}

int main()
{
	int nCasos = 0;

	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resolver();

	return 0;
}