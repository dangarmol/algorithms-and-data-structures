#include "SetOfInts1.h"
#include "SetOfInts2.h"
#include "SetOfInts3.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

SetOfInts3 valores(vector<int> v, int nValores)
{
	SetOfInts3 buscar;
	sort(v.begin(), v.end());

	int i = 0, j = 0;

	while (j < v.size() && i < nValores)
	{
		if (buscar.getMax() < v[j])
		{
			buscar.add(v[j]);
			i++;
		}

		j++;
	}

	return buscar;
}

bool ejecutar()
{
	int numero;
	cin >> numero;

	if (numero == 0)
		return false;

	int aux;
	vector<int> v;
	SetOfInts3 buscar;

	do
	{
		cin >> aux;
		if (aux != -1)
		{
			v.push_back(aux);
		}
	} 
	while (aux != -1);

	buscar = valores(v, numero);

	cout << buscar << endl;

	return true;
}

void ejecutar1()
{
	SetOfInts1 s1, s2;
	int nCasos;

	cin >> nCasos;

	for (int i = 0; i < nCasos; i++)
	{
		cin >> s1;
		cin >> s2;

		if (s1 == s2)
			cout << "iguales" << endl;
		else
			cout << "distintos" << endl;
	}
}

void ejecutar2()
{
	SetOfInts2 s1, s2;
	int nCasos;

	cin >> nCasos;

	for (int i = 0; i < nCasos; i++)
	{
		cin >> s1;
		cin >> s2;

		if (s1 == s2)
			cout << "iguales" << endl;
		else
			cout << "distintos" << endl;
	}
}

void ejecutar3()
{
	SetOfInts3 s1, s2;
	int nCasos;

	cin >> nCasos;

	for (int i = 0; i < nCasos; i++)
	{
		cin >> s1;
		cin >> s2;

		if (s1 == s2)
			cout << "iguales" << endl;
		else
			cout << "distintos" << endl;
	}
}

int main()
{
	//ejecutar1();
	//ejecutar2();
	//ejecutar3();
	//while (ejecutar());
}