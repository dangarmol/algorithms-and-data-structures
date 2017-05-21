#include "Hora.h"
#include "Pelicula.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void busqueda(vector<Hora> horarios, Hora aux)
{
	int pos = -1;

	for (int i = 0; i < horarios.size() && pos == -1; i++)
	{
		if (aux < horarios[i])
		{
			pos = i;
		}
	}

	if (pos != -1)
		cout << horarios[pos] << endl;
	else
		cout << "NO" << endl;
}

bool resuelveCaso()
{
	int nPeliculas;

	cin >> nPeliculas;

	if (nPeliculas == 0)
		return false;

	vector<Pelicula>pelicula;

	for (int i = 0; i < nPeliculas; i++)
	{
		try
		{
			Pelicula auxP;
			cin >> auxP;
			pelicula.push_back(auxP);
		}
		catch (invalid_argument &ia){}
	}

	sort(pelicula.begin(), pelicula.end());

	for (int i = 0; i < pelicula.size(); i++)
	{
		cout << pelicula[i];
	}

	cout << "---" << endl;

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}