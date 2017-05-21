#include <iostream>
#include <math.h>

using namespace std;

int complementario(int n, int e, int acu)
{
	if (n / 10 == 0)
		return acu + ((9 - (n % 10)) * e);
	else
		complementario(n / 10, e * 10, acu + ((9 - (n % 10)) * e));
	
	
	/*
	if (n <= 9)
		return 9 - n;
	else
		return (complementario(n/10) * 10) + complementario(n % 10);	
	*/
}

int complementario(int n)
{
	return complementario(n,1,0);
}

bool resuelve()
{
	int n;
	bool resuelve = false;
	cin >> n;

	if (n != -1)
	{
		cout << complementario(n) << endl;
		resuelve = true;
	}

	return resuelve;
}

int main()
{
	while (resuelve());
	return 0;
}