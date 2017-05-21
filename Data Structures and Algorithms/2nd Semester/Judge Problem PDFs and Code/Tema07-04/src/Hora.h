#include "Error.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

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
		const Hora& operator+ (const Hora &h);
		friend ostream & operator<<(ostream &o, const Hora &h);
		friend istream & operator >> (istream &i, Hora &h);
};
#endif