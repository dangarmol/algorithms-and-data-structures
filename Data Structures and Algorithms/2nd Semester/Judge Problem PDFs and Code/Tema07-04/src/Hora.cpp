#include "Error.h"
#include "Hora.h"

using namespace std;

// Constructors

	Hora::Hora()
	{
		_hora = 0;
		_minuto = 0;
		_segundo = 0;
	}

	Hora::Hora(const int hora, const int minuto, const int segundo)
	{
		if (hora >= 0 && minuto >= 0 && segundo >= 0 && hora < 24 && minuto < 60 && segundo < 60)
		{
			_hora = hora;
			_minuto = minuto;
			_segundo = segundo;
		}
		else
			throw invalid_argument("ERROR");
	}

// Public methods

	int Hora::getHora() const
	{
		return _hora;
	}

	int Hora::getMinuto() const
	{
		return _minuto;
	}

	int Hora::getSegundo() const
	{
		return _segundo;
	}

	bool Hora::operator<(const Hora & h) const
	{
		bool esMayor = false;

		if (_hora <= h.getHora())
		{
			if (_hora != h.getHora())
			{
				esMayor = true;
			}
			else
			{
				if (_minuto <= h.getMinuto())
				{
					if (_minuto != h.getMinuto())
					{
						esMayor = true;
					}
					else
					{
						if (_segundo <= h.getSegundo())
						{
							esMayor = true;
						}
					}
				}
			}
		}
		return esMayor;
	}

	const Hora& Hora::operator+ (const Hora &h)
	{
		_segundo += h.getSegundo();

		if (_segundo > 59)
		{
			_minuto += (_segundo / 60);
			_segundo = (_segundo % 60);
		}

		_minuto += h.getMinuto();

		if (_minuto > 59)
		{
			_hora += (_minuto / 60);
			_minuto = (_minuto % 60);
		}

		_hora += h.getHora();

		if (_hora > 23)
		{
			throw invalid_argument("Error");
		}

		return *this;
	}

	ostream& operator <<(ostream &o, const Hora &h)
	{
		o << setfill('0') << setw(2) << h._hora << ":" << setfill('0') << setw(2) << h._minuto << ":" << setfill('0') << setw(2) << h._segundo;
		return o;
	}

	istream & operator >> (istream &i, Hora &h)
	{
		int hora, minuto, segundo;
		i >> hora;
		i.ignore();
		i >> minuto;
		i.ignore();
		i >> segundo;
		h = Hora(hora, minuto, segundo);
		return i;
	}