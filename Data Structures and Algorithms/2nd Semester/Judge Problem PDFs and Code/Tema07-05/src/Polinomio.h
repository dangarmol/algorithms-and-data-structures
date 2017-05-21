#include "Error.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

#ifndef _POLINOMIO_H_
#define _POLINOMIO_H_

struct Monomio 
{
	int monomio;
	int grado;
};

class Polinomio
{
private:
	vector<Monomio>monomios;

public:
	Polinomio();
	long long int elevar(int valor, int gradoMonomio);
	void agregarMonomio(int monomio, int gradoMonomio);
	long long int evaluarPolinomio(int valor);
};
#endif