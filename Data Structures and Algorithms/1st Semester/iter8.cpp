#include <iostream>

using namespace std;

bool menorApartir(int v[], int n, int p)
{
	int maximo = v[0];
	bool centinela = true;

	for (int k = 0; k <= p; k++)
		if (v[k] > maximo)
			maximo = v[k];

	for (int k = p + 1; k < n && centinela; k++)
		if (v[k] <= maximo)
			centinela = false;

	return centinela;
}

void resuelve()
{
	int v[10000];
	int n, p;
	cin >> n;
	cin >> p;

	for (int k = 0; k < n; k++)
		cin >> v[k];

	if (menorApartir(v, n, p))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}