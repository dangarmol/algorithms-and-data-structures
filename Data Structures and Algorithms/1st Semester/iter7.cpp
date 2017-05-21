#include <iostream>
#include <math.h>

using namespace std;

int dinero(int n)
{
	int r = 0, k = 0, s = 0;
	int v[10000];

	while (s < n)
	{
		if (r < 2)
		{
			v[k] = 1;
			s += 1;
		}
		else
		{
			v[k] = (2 * v[k - 2]) + v[k - 1];
			s += v[k];
		}
		r++;
		k++;
	}

	return r;
}

void resuelve()
{
	int n;
	cin >> n;
	cout << dinero(n) << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for (int k = 0; k < nCasos; k++)
		resuelve();
	return 0;
}