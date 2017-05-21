#include "Arbin.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

template<class T>
void planificarRescate(Arbin<T> const &a, int &generaciones, int &max)
{
	if(!a.hijoIz().esVacio() && !a.hijoDr().esVacio())
	{
		int generacionesIz = 0, generacionesDr = 0;

		planificarRescate(a.hijoIz(), generacionesIz, max);
		planificarRescate(a.hijoDr(), generacionesDr, max);

		generaciones++;

		if (generacionesIz != 0 && generacionesDr != 0)
			generaciones += (generacionesIz > generacionesDr) ? generacionesDr : generacionesIz;

		if (generaciones > max)
			max = generaciones;
	}
	else if(!a.hijoIz().esVacio())
	{
		int generacionesIz = 0;
		generaciones = 0;
		planificarRescate(a.hijoIz(), generacionesIz, max);
	}
}


Arbin<int> leerArbol()
{
	int elem;
	cin >> elem;

	Arbin<int> hi, hd;

	if (elem == 0)
	{
		hi = Arbin<int>();
		hd = Arbin<int>();
	}
	else if (elem == 1)
	{
		hi = leerArbol();
		hd = Arbin<int>();
	}
	else
	{
		hi = leerArbol();
		hd = leerArbol();
	}

	return Arbin<int>(hi, 0, hd);
}

void resuelveCaso()
{
	Arbin<int> rutas;
	int generaciones = 0, max = 0;
	rutas = leerArbol();
	planificarRescate(rutas, generaciones, max);
	cout << max << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
