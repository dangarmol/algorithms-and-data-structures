#include <iostream>
#include <string>
using namespace std;

void resolverCaso(int v[], const int &n, bool &existe, int &p) 
{
	for (int k = 0; k < n && existe; k++)
		if (v[k] % 2 == 0)
			if(p - k == 0)
				p++;
			else 
				existe = false;
}

void resolver() 
{
	int n;
	int p = 0;
	int v[10000];
	bool existe = true;

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	resolverCaso(v, n, existe, p);

	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;
}

int main() {
	int nCasos = 0;
	cin >> nCasos;

	for (int i = 0; i < nCasos; ++i)
		resolver();

	return 0;
}