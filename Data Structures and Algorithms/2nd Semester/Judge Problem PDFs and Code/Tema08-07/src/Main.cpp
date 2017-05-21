#include "Stack.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

bool resuelveCaso()
{
	int nWagon;

	cin >> nWagon;

	if(nWagon == 0)
		return false;

	int aux, nLeido = 0, insertarPila = 1;
	bool centinela = true;
	Stack<int> in;

	while(nLeido < nWagon && centinela)
	{
		cin >> aux;

		while(insertarPila <= aux)
		{
			cout << "Wagon " << insertarPila << " in" << endl;
			in.push(insertarPila);
			insertarPila++;
		}

		if(in.top() == aux)
		{
			cout << "Wagon " << aux << " out" << endl;
			in.pop();
		}
		else
			centinela = false;

		nLeido++;
	}

	while(insertarPila <= nWagon)
	{
		cout << "Wagon " << insertarPila << " in" << endl;
		insertarPila++;
	}

	if(centinela)
		cout << "POSSIBLE" << endl;
	else
	{
		while(nLeido < nWagon)
		{
			cin >> aux;
			nLeido++;
		}

		cout << "IMPOSSIBLE" << endl;
	}

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}
