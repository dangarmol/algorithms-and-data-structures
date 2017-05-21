#include <iostream>

using namespace std;

int resuelve(int v[], const int &nElem) {
	int sum = 0;
	int pow = 1;
	for (int i = 0; i < nElem; i++)
	{
		if (v[i] == pow) sum += v[i];
		pow *= 2;
	}
	return sum;
}

int main() {
	int v[20];
	int nCasos, nElem;
	cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) {
		cin >> nElem;
		for (int j = 0; j < nElem; ++j)
		{
			cin >> v[j];
		}
		cout << resuelve(v, nElem) << endl;
	}
	return 0;
}