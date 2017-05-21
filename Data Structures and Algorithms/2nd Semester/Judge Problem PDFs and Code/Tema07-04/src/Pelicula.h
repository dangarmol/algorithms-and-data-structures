#include "Hora.h"
#include <iostream>
#include <iomanip>

using namespace std;

#ifndef _PELICULA_H_
#define _PELICULA_H_

class Pelicula
{
private:
	Hora _inicio, _fin;
	string _nombre;
public:
	Pelicula();
	Pelicula(const Hora inicio, const Hora fin, const string nombre);
	Hora getInicio() const;
	Hora getFin() const;
	string getNombre() const;
	bool operator< (const Pelicula &p) const;
	friend ostream& operator<< (ostream &o, const Pelicula &h);
	friend istream& operator>> (istream &o, Pelicula &h);
};
#endif