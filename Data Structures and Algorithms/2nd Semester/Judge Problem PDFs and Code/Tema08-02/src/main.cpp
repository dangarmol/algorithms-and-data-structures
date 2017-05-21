#include "Queue.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

void resolver()
{
	Queue<int> s;
	int nInverso, aux;

	do
	{
		cin >> aux;

		if (aux != -1)
			s.push_back(aux);
	} 
	while (aux != -1);

	cin >> nInverso;

	s.imprimir();
	s.injusto(nInverso);
	s.imprimir();
}

int main()
{
	int nCasos;

	cin >> nCasos;
	for (int k = 0; k < nCasos; k++)
		resolver();

	return 0;
}