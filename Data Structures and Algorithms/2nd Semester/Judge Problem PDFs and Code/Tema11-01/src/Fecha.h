#ifndef __FECHA_H
#define __FECHA_H

class fecha
{

private:
	int _dia, _hora, _minuto;

public:
	fecha()
	{
		_dia = 0;
		_hora = 0;
		_minuto = 0;
	}

	fecha(const int &dia, const int &hora, const int &minuto)
	{
		_dia = dia;
		_hora = hora;
		_minuto = minuto;
	}

	bool operator< (const fecha &fecha) const
	{
		bool esMayor = false;
		if (_dia <= fecha.getDia())
		{
			if (_dia != fecha.getDia())
			{
				esMayor = true;
			}
			else
			{
				if (_hora <= fecha.getHora())
				{
					if (_hora != fecha.getHora())
					{
						esMayor = true;
					}
					else
					{
						if (_minuto <= fecha.getMinuto())
						{
							esMayor = true;
						}
					}
				}
			}
		}

		return esMayor;
	}

	bool operator== (const fecha &fecha) const
	{
		return _dia == fecha.getDia() && _hora == fecha.getHora() && _minuto == fecha.getMinuto();
	}

	int getDia() const
	{
		return _dia;
	}

	int getHora() const
	{
		return _hora;
	}

	int getMinuto() const
	{
		return _minuto;
	}
};

#endif