#include "Arbin.h"
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

void resuelveCaso()
{
	int nodos = 0, hojas = 0, altura = 0;
	Arbin<char> a = leerArbol('.');
	a.numNodos(nodos, hojas, altura);
	cout << nodos << " " << hojas << " " << altura << endl;
}

int main()
{
	int nCasos;
	cin >> nCasos;

	for(int i = 0; i < nCasos; i++)
		resuelveCaso();
	return 0;
}
