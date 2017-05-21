#include "Arbin.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

template<class T>
void riosNavegables(Arbin<T> const &a, int &contador, int &n)
{
	if(a.hijoIz().esVacio() && a.hijoDr().esVacio())
	{
		contador++;
	}
	else
	{
		int contadorIz = 0, contadorDr = 0;

		if(!a.hijoIz().esVacio())
		{
			riosNavegables(a.hijoIz(), contadorIz, n);

			if(contadorIz > 2)
				n++;
		}

		if(!a.hijoDr().esVacio())
		{
			riosNavegables(a.hijoDr(), contadorDr, n);

			if(contadorDr > 2)
				n++;
		}

		contador = contadorIz + contadorDr;

		if(a.raiz() != 0)
		{
			contador -= a.raiz();
			if(contador < 0)
				contador = 0;
		}
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
	int contador = 0, n = 0;

	rutas = leerArbol(-1);
	if(!rutas.esVacio())
		riosNavegables(rutas, contador, n);

	cout << n << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
