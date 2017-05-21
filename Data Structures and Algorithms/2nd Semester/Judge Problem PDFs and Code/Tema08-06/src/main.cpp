#include "Queue.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

bool resuelveCaso()
{
	int aux;

	cin >> aux;

	if(!cin)
		return false;

	if(aux != 0)
	{
		Queue<int> q;

		do
		{
			q.push_back(aux);
			cin >> aux;
		}
		while(aux != 0);

		q.duplicar();
		q.imprimir();
	}

	cout << endl;

	return true;
}

int main()
{
	while(resuelveCaso());
	return 0;
}
