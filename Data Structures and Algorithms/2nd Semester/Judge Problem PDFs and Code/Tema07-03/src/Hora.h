#include "Error.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

#ifndef _HORA_H_
#define _HORA_H_

class Hora
{
	private:
		int _hora, _minuto, _segundo;

	public:
		Hora();
		Hora(const int hora, const int minuto, const int segundo);
		int getHora() const;
		int getMinuto() const;
		int getSegundo() const;
		bool operator < (const Hora &h) const;
		friend ostream & operator<<(ostream &o, const Hora &h);
		friend istream & operator >> (istream &i, Hora &h);
};
#endif