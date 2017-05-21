#include "Arbin.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
Arbin<T> leerArbol(T const &vacio)
{
	T aux;
	cin >> aux;

	if (aux == vacio)
		return Arbin<T>();
	else
	{
		Arbin<T> a1 = leerArbol(vacio);
		Arbin<T> a2 = leerArbol(vacio);
		return Arbin<T>(a1, aux, a2);
	}
}

template<class T>
void getMinimo(Arbin<T> const &a, T &min, const T &vacio)
{
	if(min == vacio || a.raiz() < min)
	{
		min = a.raiz();
	}

	if(!a.hijoIz().esVacio())
	{
		getMinimo(a.hijoIz(), min, vacio);
	}

	if(!a.hijoDr().esVacio())
	{
		getMinimo(a.hijoDr(), min, vacio);

	}
}

bool resuelveCaso()
{
	char opcion;
	cin >> opcion;

	if(!cin)
		return false;

	if(opcion == 'N')
	{
		int min, vacio;
		min = vacio = -1;
		Arbin<int> a = leerArbol(vacio);

		if(!a.esVacio())
		{
			getMinimo(a, min, vacio);
			cout << min;
		}
	}
	else
	{
		string min, vacio;
		min = vacio = "#";
		Arbin<string> a = leerArbol(vacio);

		if(!a.esVacio())
		{
			getMinimo(a, min, vacio);
			cout << min;
		}
	}

	cout << endl;
	return true;
}

int main()
{
	while(resuelveCaso());
	return 0;
}
