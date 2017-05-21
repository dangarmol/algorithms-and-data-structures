#include "HashMap.h"
#include "AvlTreeMap.h"
#include "List.h"
#include "Fecha.h"
#include "Exceptions.h"
#include <string>
#include <stdexcept>
using namespace std;

#ifndef __CONSULTORIO_H
#define __CONSULTORIO_H

struct consulta
{
	string nombre;
	int hora;
	int minuto;
};

class consultorio
{
private:
	HashMap <string, AvlTreeMap<fecha, string>> consultas;

public:
	consultorio(){}
	void nuevoMedico(const string &medico) // constante
	{
		if (!consultas.contains(medico))
		{
			AvlTreeMap<fecha, string> aux;
			consultas.insert(medico, aux);
		}
	}

	void pideConsulta(string paciente, string medico, fecha fecha) // constante
	{
		if (consultas.contains(medico))
		{
			if (!consultas[medico].contains(fecha))
				consultas[medico].insert(fecha, paciente);
			else
				throw invalid_argument("Fecha ocupada");
		}
		else
			throw invalid_argument("Medico no existente");
	}

	string siguientePaciente(string medico) // comentar a Miguel, puede ser log n, pero en verdad constante ya que solo avanza hacia la izquierda
	{
		if (consultas.contains(medico))
		{
			if (!consultas[medico].empty())
			{
				AvlTreeMap<fecha, string>::ConstIterator it = consultas[medico].cbegin();
				return it.value();
			}
			else
				throw invalid_argument("No hay pacientes");
		}
		else
			throw invalid_argument("Medico no existente");
	}

	void atiendeConsulta(string medico) // lo mismo que el anterior
	{
		if (consultas.contains(medico))
		{
			if (!consultas[medico].empty())
			{
				AvlTreeMap<fecha, string>::ConstIterator it = consultas[medico].cbegin();
				consultas[medico].erase(it.key());
			}
			else
				throw invalid_argument("No hay pacientes");
		}
		else
			throw invalid_argument("Medico no existente");
	}

	const List<consulta> listaPacientes(string medico, int dia) // orden n respecto al numero de n consultas que tiene un medico
	{
		if (consultas.contains(medico))
		{
			List<consulta> lConsulta;
			AvlTreeMap<fecha, string>::ConstIterator it = consultas[medico].cbegin();
			AvlTreeMap<fecha, string>::ConstIterator itFin = consultas[medico].cend();

			while (it != itFin)
			{
				if (it.key().getDia() == dia)
				{
					consulta aux;
					aux.nombre = it.value();
					aux.hora = it.key().getHora();
					aux.minuto = it.key().getMinuto();
					lConsulta.push_back(aux);
				}

				++it;
			}

			return lConsulta;
		}
		else
			throw invalid_argument("Medico no existente");
	}
};

#endif