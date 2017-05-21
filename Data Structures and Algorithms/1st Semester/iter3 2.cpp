#include <iostream>
#include <math.h>

using namespace std;

int log(int b, int n)
{
	int r = 0;
	
	while (pow(b,r+1) <= n)
		r++;

	return r;
}

void resuelve()
{
	int b, n;
	cin >> b;
	cin >> n;

	cout << log(b, n) << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}