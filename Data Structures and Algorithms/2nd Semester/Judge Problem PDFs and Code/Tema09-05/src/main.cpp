#include "Arbin.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

template<class T>
void arbolGenealogico(Arbin<T> const &a, bool &esGenealogico, int &generaciones)
{
	if(!a.hijoIz().esVacio() && !a.hijoDr().esVacio())
	{
		if(a.hijoIz().raiz() <= a.raiz() - 18 && a.hijoDr().raiz() <= a.hijoIz().raiz() - 2)
		{
			int generacionesIz = 0, generacionesDr = 0;
			bool esGenealogicoIz = true, esGenealogicoDr = true;

			arbolGenealogico(a.hijoIz(), esGenealogicoIz, generacionesIz);
			arbolGenealogico(a.hijoDr(), esGenealogicoDr, generacionesDr);

			if(esGenealogicoIz && esGenealogicoDr)
				generaciones = max(generacionesIz, generacionesDr) + 1;
			else
				esGenealogico = false;
		}
		else
			esGenealogico = false;
	}
	else if(!a.hijoIz().esVacio())
	{
		if(a.hijoIz().raiz() <= a.raiz() - 18)
		{
			int generacionesIz = 0;
			bool esGenealogicoIz = true;

			arbolGenealogico(a.hijoIz(), esGenealogicoIz, generacionesIz);

			if(esGenealogicoIz)
				generaciones = generacionesIz + 1;
			else
				esGenealogico = false;
		}
		else
			esGenealogico = false;
	}
	else if(!a.hijoDr().esVacio())
	{
		esGenealogico = false;
	}
	else
	{
		generaciones++;
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
	int generaciones = 0;
	bool esGenealogico = true;

	rutas = leerArbol(-1);
	if(!rutas.esVacio())
		arbolGenealogico(rutas, esGenealogico, generaciones);

	if(esGenealogico)
		cout << "YES " << generaciones << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
