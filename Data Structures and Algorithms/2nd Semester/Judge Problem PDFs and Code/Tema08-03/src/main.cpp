#include "Queue.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

void resolver()
{
	Queue<int> fila, amigos;
	int nColar, aux;

	do
	{
		cin >> aux;

		if (aux != -1)
			fila.push_back(aux);
	} 
	while (aux != -1);

	cin >> nColar;

	do
	{
		cin >> aux;

		if (aux != -1)
			amigos.push_back(aux);
	} while (aux != -1);

	fila.imprimir();
	fila.colar(amigos, nColar);
	fila.imprimir();
}

int main()
{
	int nCasos;

	cin >> nCasos;
	for (int k = 0; k < nCasos; k++)
		resolver();

	return 0;
}