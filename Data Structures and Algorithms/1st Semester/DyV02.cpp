#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>

using namespace std;
const int K = 31543;

long long int elevarNumero(int x, int n)
{
	int p;
	if (n == 0)
		return 1;
	else if (n == 1)
		return x % K;
	else
	{
		int solucion = elevarNumero(x, n / 2);
		solucion = (((solucion) % K) * ((solucion) % K)) % K;

		if (n % 2 == 1)
			solucion = (((solucion) % K) * ((x) % K)) % K;

		return solucion;
	}
}

bool resuelve()
{
	int x, n;

	cin >> x >> n;

	if (x == 0 && n == 0)
		return false;

	cout << elevarNumero(x, n) << endl;
	return true;
}

int main()
{
	while (resuelve());
	return 0;
}