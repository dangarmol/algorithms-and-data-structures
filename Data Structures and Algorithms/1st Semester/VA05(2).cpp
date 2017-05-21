#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

struct Cancion
{
	int duracion = 0;
	int puntuacion = 0;
};

struct Cinta
{
	int primera;
	int segunda;
};

bool esSolucion(int k, int n)
{
	return k == n - 1;
}

bool esPrometedora(int puntuacion, int puntuacionMaxima, int posibleMaximaPuntuacion)
{
	return posibleMaximaPuntuacion + puntuacion > puntuacionMaxima;
}

void tratarSolucion(int puntuacion, int &puntuacionMaxima)
{
	if (puntuacion > puntuacionMaxima)
		puntuacionMaxima = puntuacion;
}

void calcularPuntuacion(Cancion v[], Cinta cinta, bool m[], int k, int n, int puntuacion, int &puntuacionMaxima, int posibleMaximaPuntuacion, int minimaDuracion[])
{
		bool primera = false, segunda = false;

		puntuacion += v[k].puntuacion;

		if (cinta.primera - v[k].duracion >= 0)
		{
			cinta.primera -= v[k].duracion;
			primera = true;
		}
		else if (cinta.segunda - v[k].duracion >= 0)
		{
			cinta.segunda -= v[k].duracion;
			segunda = true;
		}

		if ((primera || segunda))
		{
			if (esSolucion(k, n) || (cinta.primera - minimaDuracion[k] < 0 && cinta.segunda - minimaDuracion[k] < 0))
				tratarSolucion(puntuacion, puntuacionMaxima);
			else
			{
				calcularPuntuacion(v, cinta, m, k + 1, n, puntuacion, puntuacionMaxima, posibleMaximaPuntuacion, minimaDuracion);
			}
		}

		puntuacion -= v[k].puntuacion;

		if (primera)
		{
			cinta.primera += v[k].duracion;

		}
		else if (segunda)
		{
			cinta.segunda += v[k].duracion;
		}

		if (esSolucion(k, n) || (cinta.primera - minimaDuracion[k] < 0 && cinta.segunda - minimaDuracion[k] < 0))
			tratarSolucion(puntuacion, puntuacionMaxima);
		else
		{
			calcularPuntuacion(v, cinta, m, k + 1, n, puntuacion, puntuacionMaxima, posibleMaximaPuntuacion, minimaDuracion);
		}
}

bool resuelve()
{
	Cancion v[50];
	Cinta cinta;
	bool m[50];
	int n, puntuacionMaxima = 0, posibleMaximaPuntuacion = 0, minimaDuracion[50] = {0};

	cin >> n;

	if (n == 0)
		return false;

	cin >> cinta.primera;
	cinta.segunda = cinta.primera;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].duracion >> v[i].puntuacion;
		posibleMaximaPuntuacion += v[i].puntuacion;
		m[i] = false;
	}

	if (n == 1)
	{
		if (cinta.primera >= v[0].duracion)
			puntuacionMaxima = v[0].puntuacion;
	}
	else
	{
		minimaDuracion[n - 2] = v[n - 1].duracion;

		for (int i = n - 3; i >= 0; i--)
		{
			if (v[i].duracion < minimaDuracion[i + 1])
				minimaDuracion[i] = v[i].duracion;
			else
				minimaDuracion[i] = minimaDuracion[i + 1];
		}

		calcularPuntuacion(v, cinta, m, 0, n, 0, puntuacionMaxima, posibleMaximaPuntuacion, minimaDuracion);
	}

	cout << puntuacionMaxima << endl;

	return true;
}

int main()
{
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelve());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}