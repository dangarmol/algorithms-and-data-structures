#include "TreeMap.h"
#include "List.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

void mostrar(TreeMap<string, List<int>> &arbol) 
{
	TreeMap<string, List<int>>::Iterator it = arbol.begin();
	TreeMap<string, List<int>>::Iterator itFin = arbol.end();

	while (it != itFin) 
	{
		cout << it.key() << " ";
		
		List<int> l = it.value();

		List<int>::Iterator it1 = l.begin();
		List<int>::Iterator itFin1 = l.end();

		while (it1 != itFin1) 
		{
			cout << it1.elem() << " ";
			++it1;
		}
		cout << endl;
		it++;
	}

	cout << "----" << endl;
}

void resuelveCaso(int numLineas) 
{
	TreeMap<string, List<int>> arbol;
	string palabra;
	char c;

	for (int linea = 1; linea <= numLineas; linea++)
	{
		cin.get(c);
		while (c != '\n') 
		{
			cin.unget();
			cin >> palabra;
			transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

			if (palabra.size() > 2)
			{
				if (!arbol.contains(palabra))
				{
					arbol[palabra].push_back(linea);
				}
				else
				{
					if (arbol[palabra].back() != linea)
					{
						arbol[palabra].push_back(linea);
					}
				}
			}

			cin.get(c);
		}
	}

	mostrar(arbol);
}

int main()
{
	int numLineas;
	char c;
	cin >> numLineas; cin.get(c);
	while (numLineas != 0) 
	{
		resuelveCaso(numLineas);
		cin >> numLineas; cin.get(c);
	}
}
