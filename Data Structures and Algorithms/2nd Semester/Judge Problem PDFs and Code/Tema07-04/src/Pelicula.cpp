#include "Error.h"
#include "Pelicula.h"

using namespace std;

// Constructors

Pelicula::Pelicula()
{
	_inicio = Hora();
	_fin = Hora();
	_nombre = "";
}

Pelicula::Pelicula(Hora inicio, Hora fin, string nombre)
{
	_inicio = inicio;
	_fin = fin;
	_nombre = nombre;
}

// Public methods

Hora Pelicula::getInicio() const
{
	return _inicio;
}

Hora Pelicula::getFin() const
{
	return _fin;
}

string Pelicula::getNombre() const
{
	return _nombre;
}

bool Pelicula::operator < (const Pelicula &p) const
{
	bool esMayor = false;

	if (_fin.getHora() == p.getFin().getHora() && _fin.getMinuto() == p.getFin().getMinuto() && _fin.getSegundo() == p.getFin().getSegundo())
	{
		if (_nombre < p.getNombre())
		{
			esMayor = true;
		}
	}
	else
	{
		esMayor = _fin < p.getFin();
	}

	return esMayor;
}

ostream& operator << (ostream &o, const Pelicula &p)
{
	o << p._fin << " " << p._nombre << endl;
	return o;
}

istream& operator>> (istream &i, Pelicula &p)
{
	Hora auxInicio, auxFin;
	string auxNombre;
	i >> auxInicio;
	i >> auxFin;
	i.ignore();
	getline(cin, auxNombre);
	auxFin = auxFin + auxInicio;

	p._inicio = auxInicio;
	p._fin = auxFin;
	p._nombre = auxNombre;

	return i;
}