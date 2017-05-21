#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
void duplicar(List<T> &l)
{
	List<T>::Iterator it = l.begin();
	List<T>::Iterator itEnd = l.end();

	while (it != itEnd)
	{
		l.insert(it.elem(), it);
		++it;
	}
}

template <class T>
void imprimir(List<T> l)
{
	List<T>::Iterator it = l.begin();
	List<T>::Iterator itEnd = l.end();

	while (it != itEnd)
	{
		cout << it.elem() << " ";
		++it;
	}
}

bool resuelveCaso()
{
	int aux;

	cin >> aux;

	if(!cin)
		return false;

	if(aux != 0)
	{
		List<int> l;

		do
		{
			l.push_back(aux);
			cin >> aux;
		}
		while(aux != 0);

		duplicar(l);
		imprimir(l);
	}

	cout << endl;

	return true;
}

int main()
{
	while(resuelveCaso());
	return 0;
}
