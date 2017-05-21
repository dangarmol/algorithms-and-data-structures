#include "Hora.h"
#include <iostream>
#include <vector>

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
	int nHorarios, nConsultas;

	cin >> nHorarios >> nConsultas;

	if (nHorarios == 0 && nConsultas == 0)
		return false;

	vector<Hora> horarios;
	Hora aux;

	for (int i = 0; i < nHorarios; i++)
	{
		cin >> aux;
		horarios.push_back(aux);
	}

	for (int i = 0; i < nConsultas; i++)
	{
		try
		{
			cin >> aux;
			busqueda(horarios, aux);
		}
		catch (invalid_argument)
		{
			cout << "ERROR" << endl;
		}
	}

	cout << "---" << endl;

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}