#include <iostream>
#include <math.h>

using namespace std;

int colar(int v[], int n)
{
	int c = 0;
	int m = v[n - 1];
	
	for (int k = n - 1; k >= 0; k--)
	{
		if (v[k] <= m)
			m = v[k];
		else
			c++;
	}

	return c;
}

void resuelve()
{
	int v[100000];
	int n;

	cin >> n;
	for (int k = 0; k < n; k++)
		cin >> v[k];

	cout << colar(v, n) << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}