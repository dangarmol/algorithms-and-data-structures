#include "Set.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template<class T>
void valores(vector<T> v, Set<T> &buscar, int nCasos)
{
	for (int i = 0; i < v.size(); i++)
	{
		buscar.add(v[i]);
	}
	
	int remove = buscar.getSize() - nCasos;

	for (int i = 0; i < remove; i++)
	{
		buscar.removeMin();
	}
}

template<class T>
void mostrar(Set<T> setV, int nCasos)
{
	for (int i = 0; i < nCasos; i++)
	{
		cout << setV.getMin() << " ";
		setV.removeMin();
	}
	cout << endl;
}

bool resolver()
{
	char op;

	cin >> op;

	if (!cin)
		return false;
	
	int nCasos;
	cin >> nCasos;

	if (op == 'N')
	{
		int aux;
		vector<int> v;
		Set<int> setV;

		do
		{
			cin >> aux;
			if (aux != -1)
				v.push_back(aux);
		}
		while (aux != -1);

		valores(v, setV, nCasos);
		mostrar(setV, nCasos);
	}
	else
	{
		string aux;
		vector<string> v;
		Set<string> setV;

		do
		{
			cin >> aux;
			if (aux != "FIN")
				v.push_back(aux);
		} 
		while (aux != "FIN");

		valores(v, setV, nCasos);
		mostrar(setV, nCasos);
	}

	return true;
}

int main()
{
	while(resolver());
}