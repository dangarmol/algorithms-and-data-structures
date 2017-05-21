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

void resuelveCaso()
{
	int vacio = -1;
	vector<int> frontera;
	Arbin<int> arbol = leerArbol(vacio);
	arbol.fronteras(frontera, vacio);

	for(unsigned int i = 0; i < frontera.size(); ++i)
	{
		cout << frontera[i] << " ";
	}

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
