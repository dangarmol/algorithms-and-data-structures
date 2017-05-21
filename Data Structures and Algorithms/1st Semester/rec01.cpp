#include <iostream>
#include <math.h>

using namespace std;

int log(int b, int n, int acu, int elevado)
{
	if ((elevado * b) > n)
		return acu;
	else
		log(b, n, acu + 1, elevado*b);
}

int log(int b, int n)
{
	int acu = 0, elevado = 1;
	return log(b, n, acu, elevado);
}

void resuelve()
{
	int b, n;
	cin >> b >> n;
	cout << log(b,n) << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}