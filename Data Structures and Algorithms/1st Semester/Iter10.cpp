#include <iostream>
using namespace std;

void resolverCaso(int v[], const int &n)
{
	int maxLength = 0, lenghtCounter = 0, maxIndex = -1;

	for (int i = 0; i < n; ++i)
	{
		if (v[i] % 2 == 0)
			lenghtCounter++;
		else
			lenghtCounter = 0;

		if (maxLength <= lenghtCounter && lenghtCounter > 0)
		{
			maxLength = lenghtCounter;
			maxIndex = i;
		}
	}

	if (maxIndex == -1)
		cout << "Vacio" << endl;
	else
		cout << maxLength << " -> [" << (maxIndex - maxLength) + 1 << "," << maxIndex + 1 << ")" << endl;
}

void resolver()
{
	int n;
	int v[100000];

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	resolverCaso(v, n);
}

int main() {
	int nCasos = 0;
	cin >> nCasos;

	for (int i = 0; i < nCasos; ++i)
		resolver();

	return 0;
}