#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Fecha.h"
#include "Consultorio.h"
#include "List.h"

typedef string medico;
typedef string paciente;

bool resuelve()
{
	int N;
	cin >> N;

	if (!cin)
		return false;

	string inst; medico med; paciente pac;
	consultorio con;
	int d, h, m;

	for (int i = 0; i < N; ++i)
	{
		try
		{
			cin >> inst;
			if (inst == "nuevoMedico")
			{
				cin >> med;
				con.nuevoMedico(med);
			}
			else if (inst == "pideConsulta")
			{
				cin >> pac >> med >> d >> h >> m;
				fecha aux = fecha(d,h,m);
				con.pideConsulta(pac, med, aux);
			}
			else if (inst == "siguientePaciente")
			{
				cin >> med;
				pac = con.siguientePaciente(med);
				cout << "Siguiente paciente doctor " << med << '\n';
				cout << pac << '\n';
				cout << "---\n";
			}
			else if (inst == "atiendeConsulta") 
			{
				cin >> med;
				con.atiendeConsulta(med);
			}
			else if (inst == "listaPacientes")
			{
				cin >> med >> d;
				List<consulta> vec = con.listaPacientes(med, d);
				cout << "Doctor " << med << " dia " << d << '\n';
				for (consulta p : vec)
				{
					cout << p.nombre << ' ';
					cout << setfill('0') << setw(2) << p.hora << ':';
					cout << setfill('0') << setw(2) << p.minuto << '\n';
				}
				cout << "---\n";
			}
		}
		catch (invalid_argument e) { cout << e.what() << '\n' << "---\n"; }
	}

	cout << "------\n";

	return true;
}

int main() 
{
	while (resuelve());
	return 0;
}