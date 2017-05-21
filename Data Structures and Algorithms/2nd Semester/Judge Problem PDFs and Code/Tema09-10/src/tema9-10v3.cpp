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
void buscarPuerta(Arbin<T> const &a, int acu, int &nMejorDragones, int &nPuerta)
{
	if (a.hijoIz().esVacio() && a.hijoDr().esVacio())
	{
		if (acu < nMejorDragones)
		{
			nMejorDragones = acu;
			nPuerta = a.raiz();
		}
	}
	else
	{
		if (a.raiz() == 1)
			acu++;

		if(!a.hijoIz().esVacio())
			buscarPuerta(a.hijoIz(), acu, nMejorDragones, nPuerta);
		if(!a.hijoDr().esVacio())
			buscarPuerta(a.hijoDr(), acu, nMejorDragones, nPuerta);
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
	int acu = 0, nMejorDragones = INT_MAX, nPuerta = 0;

	rutas = leerArbol(-1);
	buscarPuerta(rutas, acu, nMejorDragones, nPuerta);

	cout << nPuerta << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
