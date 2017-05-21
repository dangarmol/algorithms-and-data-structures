#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

void eliminar(List<int> &l)
{
	List<int>::Iterator it = l.begin();
	List<int>::Iterator itEnd = l.end();
	int aux = -1;

	while(it != itEnd)
	{
		if(aux != -1 && aux > it.elem())
		{
			it = l.erase(it);
		}
		else
		{
			aux = it.elem();
			it++;
		}
	}
}

void imprimir(List<int> l)
{
	List<int>::Iterator it = l.begin();
	List<int>::Iterator itEnd = l.end();

	while (it != itEnd)
	{
		cout << it.elem() << " ";
		++it;
	}
}

void resuelveCaso()
{
	List<int> l;
	int aux;

	do
	{
		cin >> aux;

		if(aux != -1)
			l.push_back(aux);
	}
	while(aux != -1);

	eliminar(l);
	imprimir(l);

	cout << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;
	for(int i = 0; i < nCasos; i++)
		resuelveCaso();
	return 0;
}
