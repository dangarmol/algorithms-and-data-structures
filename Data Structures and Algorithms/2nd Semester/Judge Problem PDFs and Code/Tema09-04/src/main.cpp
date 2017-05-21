#include "Arbin.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

template<class T>
void planificarRescate(Arbin<T> const &a, int &grupos, int &max)
{
	if(!a.hijoIz().esVacio() && !a.hijoDr().esVacio())
	{
		int maxIz, maxDr, grupoIz, grupoDr;
		maxIz = maxDr = grupoIz = grupoDr = 0;

		planificarRescate(a.hijoIz(), grupoIz, maxIz);
		planificarRescate(a.hijoDr(), grupoDr, maxDr);

		grupos = grupoIz + grupoDr;

		if(maxIz > maxDr)
			max += maxIz;
		else
			max += maxDr;
	}
	else if(!a.hijoIz().esVacio())
	{
		planificarRescate(a.hijoIz(), grupos, max);
	}
	else if(!a.hijoDr().esVacio())
	{
		planificarRescate(a.hijoDr(), grupos, max);
	}

	if(a.raiz() > 0)
	{
		if(max == 0)
			grupos++;
		max += a.raiz();
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
	int grupos = 0, max = 0;
	rutas = leerArbol(-1);
	planificarRescate(rutas, grupos, max);
	cout << grupos << " " << max << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
