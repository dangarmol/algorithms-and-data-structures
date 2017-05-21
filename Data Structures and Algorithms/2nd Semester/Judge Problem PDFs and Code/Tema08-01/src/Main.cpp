#include "Stack.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

bool cerrar(char abierto, char cerrado)
{
	bool cerrar = false;

	switch (abierto)
	{
		case '(':
			cerrar = cerrado == ')';
			break;
		case '{':
			cerrar = cerrado == '}';
			break;
		case '[':
			cerrar = cerrado == ']';
			break;
	}

	return cerrar;
}

bool balanceado(string const &linea)
{
	Stack<char> p;

	for (int i = 0; i < linea.size(); i++)
	{
		if (linea[i] == '(' || linea[i] == '{' || linea[i] == '[')
		{
			p.push(linea[i]);
		}
		else if (linea[i] == ')' || linea[i] == '}' || linea[i] == ']')
		{
			if (p.empty())
				return false;
			else if (cerrar(p.top(), linea[i]))
				p.pop();
			else
				return false;
		}
	}

	if (p.empty())
		return true;
	else
		return false;
}

bool resuelveCaso()
{
	string linea;

	getline(cin, linea);

	if (linea.size() == 1 && linea.front() == '.')
		return false;

	if (balanceado(linea))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}