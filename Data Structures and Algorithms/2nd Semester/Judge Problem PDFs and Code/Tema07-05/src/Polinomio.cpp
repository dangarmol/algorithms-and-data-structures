#include "Error.h"
#include "Polinomio.h"

using namespace std;

// Constructors

Polinomio::Polinomio() {}
struct Monomio m;

// Public methods

long long int Polinomio::elevar(int valor, int gradoMonomio)
{
	long long int numero = 1;

	for (int i = 0; i < gradoMonomio; i++)
	{
		numero = numero * valor;
	}

	return numero;
}

void Polinomio::agregarMonomio(int monomio, int gradoMonomio)
{
	m.monomio = monomio;
	m.grado = gradoMonomio;
	monomios.push_back(m);
}

long long int Polinomio::evaluarPolinomio(int valor)
{
	long long int aux = 0;

	for (int i = 0; i < monomios.size(); i++)
	{
		m = monomios[i];
		aux += m.monomio * elevar(valor, m.grado);
	}

	return aux;
}