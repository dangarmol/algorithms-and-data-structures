#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int contarPares(int v[], int i, int n)
{
	int par = 0;

	for (int k = i; k < n; k++)
		if (v[k] % 2 == 0)
			par++;

	return par;
}

bool pareado(int v[], int i, int n)
{
	int m, pIzq, pDcha, difPares;

	if (n <= i + 1)
		return true;
	else
	{
		m = (i + n) / 2;
		pIzq = pareado(v, i, m);
		pDcha = pareado(v, m, n);
		difPares = abs(contarPares(v,i,m) - contarPares(v,m,n));
		return (pIzq && pDcha && (difPares <= 1));
	}
}

bool pareado(int v[], int num)
{
	return pareado(v,0,num);
}

int main() // Complejidad O(n log n)
{
	int v[] = { 3,3,1,5,4,2,9 };

	if (pareado(v, 7))
		cout << "Si" << endl;
	else
		cout << "No" << endl;

	system("pause");
	return 0;
}