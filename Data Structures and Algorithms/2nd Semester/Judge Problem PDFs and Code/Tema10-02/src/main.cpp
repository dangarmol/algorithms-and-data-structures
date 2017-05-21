#include "HashMap.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <climits>
using namespace std;

void resuelveCaso()
{
	int nPeliculas = 0, aux = 0, acu = 0, max = 0;
	HashMap<int, int> capitulos;
	cin >> nPeliculas;

	for (int i = 0; i < nPeliculas; ++i)
	{
		cin >> aux;

		if (!capitulos.contains(aux))
		{
			capitulos.insert(aux, i);
			acu++;
		}
		else
		{
			if (i - capitulos.at(aux) <= acu)
				acu = i - capitulos.at(aux);
			else
				++acu;

			capitulos.insert(aux, i);
		}

		if (acu > max)
			max = acu;
	}

	cout << max << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}
