#include "Polinomio.h"
#include <iostream>

using namespace std;

bool resuelveCaso()
{
	int monomio;

	cin >> monomio;

	if (!cin)
		return false;

	Polinomio polinomio;
	int gradoMonomio, nValor, valor;

	cin >> gradoMonomio;

	do
	{
		if (monomio != 0 || gradoMonomio != 0)
		{
			polinomio.agregarMonomio(monomio, gradoMonomio);
		}

		cin >> monomio >> gradoMonomio;
	} 
	while (monomio != 0 || gradoMonomio != 0);

	cin >> nValor;

	for (int i = 0; i < nValor; i++)
	{
		cin >> valor;
		cout << polinomio.evaluarPolinomio(valor) << " ";
	}

	cout << endl;

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}