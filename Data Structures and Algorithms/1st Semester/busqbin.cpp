#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int busqBin(int v[], int x, int a, int b)
{
	if (a == b + 1)
		return a - 1;
	else
	{
		int m = (a + b) / 2;

		if (v[m] > x)
			return busqBin(v, x, a, m - 1);
		else
			return busqBin(v, x, m + 1, b);
	}
}

int busqBin(int v[], int x, int n)
{
	return busqBin(v, x, 0, n - 1);
}

int main()
{
	int v[] = { 3,5,6,6,6,8,15 };

	cout << busqBin(v, 6, 7) << "\n";

	system("pause");
	return 0;
}