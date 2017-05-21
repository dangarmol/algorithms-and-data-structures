#include "Arbin.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <climits>
using namespace std;

template<class T>
void buscarPuerta(Arbin<T> const &a, int &nPuerta, int &nDragones)
{
	if (!a.hijoIz().esVacio() && !a.hijoDr().esVacio())
	{
		int nPuertaIz = 0, nPuertaDr = 0;
		int nDragonesIz = 0, nDragonesDr = 0;

		buscarPuerta(a.hijoIz(), nPuertaIz, nDragonesIz);
		buscarPuerta(a.hijoDr(), nPuertaDr, nDragonesDr);

		if (a.raiz() == 1)
			nDragones++;

		if (nDragonesIz > nDragonesDr)
		{
			nDragones += nDragonesDr;
			nPuerta = nPuertaDr;
		}
		else
		{
			nDragones += nDragonesIz;
			nPuerta = nPuertaIz;
		}
	}
	else if (!a.hijoIz().esVacio())
	{
		buscarPuerta(a.hijoIz(), nPuerta, nDragones);

		if (a.raiz() == 1)
			nDragones++;
	}
	else if (!a.hijoDr().esVacio())
	{
		buscarPuerta(a.hijoDr(), nPuerta, nDragones);

		if (a.raiz() == 1)
			nDragones++;
	}
	else
	{
		nPuerta = a.raiz();
	}
}

template <class T>
Arbin<T> leerArbol(const T& repVacio)
{
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else
	{
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi,elem,hd);
	}
}

void resuelveCaso()
{
	Arbin<int> rutas;
	int nPuerta = 0, nDragones = 0;

	rutas = leerArbol(-1);
	buscarPuerta(rutas, nPuerta, nDragones);

	cout << nPuerta << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
