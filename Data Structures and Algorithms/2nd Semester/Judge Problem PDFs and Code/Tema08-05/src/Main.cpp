#include "Stack.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

void mostrar(Stack<long long int> s, const long long int suma)
{
	cout << s.top();
	s.pop();

	while(!s.empty())
	{
		cout << " + " << s.top();
		s.pop();
	}

	cout << " = " << suma << endl;
}

bool resuelveCaso()
{
	long long int aux;
	Stack<long long int> s;

	cin >> aux;

	if(aux == -1)
		return false;

	long long int suma = 0;

	if(aux == 0)
		s.push(aux);
	else
	{
		while(aux > 0)
		{
			s.push(aux % 10);
			suma += aux % 10;
			aux /= 10;
		}
	}

	mostrar(s, suma);

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}
