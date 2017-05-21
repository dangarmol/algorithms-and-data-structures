#include <iostream>
#include <algorithm>
#include "iostream"
#include "fstream"
#include <stdexcept>
using namespace std;

int calcularOperacion(int n, int a, int b, bool &anular)
{
	int resultado = 0;
	if (n == 0)
		resultado = a + b;
	else if (n == 1)
		resultado = a - b;
	else if (n == 2)
		resultado = a * b;
	else
	{
		if (b != 0)
		{
			if (a % b == 0)
				resultado = a / b;
			else
				anular = true;
		}
		else
			anular = true;
	}
		
	return resultado;
}

bool esValida(bool solucion, int k, int n)
{
	bool aux = true;

	if (solucion || k == n)
		aux = false;
	return aux;
}

bool esSolucion(int k, int n, int v[], int sol[], int valor)
{
	bool aux = false;

	if (k == (n - 1))
	{
		int calculo = 0;
		bool anular = false;
		calculo = calcularOperacion(sol[0], v[0], v[1], anular);
		calculo = calcularOperacion(sol[1], calculo, v[2], anular);
		calculo = calcularOperacion(sol[2], calculo, v[3], anular);
		calculo = calcularOperacion(sol[3], calculo, v[4], anular);

		if (calculo == valor && !anular)
			aux = true;
	}

	return aux;
}

void tratarSolucion(bool &solucion)
{
	solucion = true;
}

void anagramas(int sol[], int v[], int valor, bool &solucion, int k, int n)
{
	for (int offset = 0; offset < n; offset++)
	{
		sol[k] = offset;
		if (esValida(solucion, k, n))
		{
			if (esSolucion(k, n, v, sol, valor))
				tratarSolucion(solucion);
			else
				anagramas(sol, v, valor, solucion, k + 1, n);
		}
	}
}

bool resuelve()
{
	int sol[5], v[5], valor;
	bool solucion = false;

	cin >> valor;

	for (int i = 0; i < 5; i++)
		cin >> v[i];

	if (!cin)
		return false;

	anagramas(sol, v, valor, solucion, 0, 4);
	
	if (solucion)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

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