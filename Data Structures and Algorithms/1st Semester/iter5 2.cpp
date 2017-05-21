#include <iostream>
#include <math.h>

using namespace std;

void resuelve()
{
	int v[10000];
	int n = 1, s, i, k;

	while (n != 0)
	{
		cin >> n;
		s = 0;
		i = n;
		k = 0;
	
		while (i != 0)
		{
			v[k] = i + s;
			s += i;
			cout << v[k] << " ";
			cin >> i;
			k++;
		}
		cout << endl;
	}
}

int main()
{
	resuelve();
	return 0;
}