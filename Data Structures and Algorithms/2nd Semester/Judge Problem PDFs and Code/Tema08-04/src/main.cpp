#include "List.h"

void resolver()
{
	List<int> lista;
	int quitar, aux;

	cin >> aux;

	while (aux != -1)
	{
		lista.push_back(aux);
		cin >> aux;
	}

	cin >> quitar;

	lista.imprimir();
	lista.quitar(quitar);
	lista.imprimir();
}

int main()
{
	int nCasos;

	cin >> nCasos;
	for (int k = 0; k < nCasos; k++)
		resolver();

	return 0;
}