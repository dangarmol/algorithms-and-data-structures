#include "Arbin.h"
#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Arbin<int> reconstruir(vector<int> const &preorden, vector<int> const &inorden, int preIni, int preFin, int inIni, int inFin)
{
	if (preFin < preIni) // no hay nada
		return Arbin<int>();
	else if (preFin == preIni)
		return Arbin<int>(preorden.at(preIni));
	else
	{
		int PIzIni, PIzFin;
		int PDrIni, PDrFin;
		int IIzIni, IIzFin;
		int IDrIni, IDrFin;

		int raiz = preorden.at(preIni);
		int pos = inIni;

		while (inorden.at(pos) != raiz)
			++pos;
		// Calcular indices de preorden
		PIzIni = preIni + 1;
		PIzFin = preIni + (pos - inIni);
		PDrIni = PIzFin + 1;
		PDrFin = preFin;

		// Calcular indices de inorden
		IIzIni = inIni;
		IIzFin = pos - 1;
		IDrIni = pos + 1;
		IDrFin = inFin;
		Arbin<int> a1 = reconstruir(preorden, inorden, PIzIni, PIzFin, IIzIni, IIzFin);
		Arbin<int> a2 = reconstruir(preorden, inorden, PDrIni, PDrFin, IDrIni, IDrFin);

		return Arbin<int>(a1, raiz, a2);
	}
}

template <class T>
void mostrar(List<T>* const& l)
{
	typename List<T>::ConstIterator it = l->cbegin();
	typename List<T>::ConstIterator itFin = l->cend();

	if (it != itFin)
	{
		cout << *it;
		++it;
	}
	while (it != itFin)
	{
		cout << ' ' << *it;
		++it;
	}
}

bool resuelveCaso()
{
	vector<int> preorden;
	vector<int> inorden;
	int aux;

	cin >> aux;
	if (!cin)
		return false;

	while (aux != -1)
	{
		preorden.push_back(aux);
		cin >> aux;
	}
	cin >> aux;

	while (aux != -1)
	{
		inorden.push_back(aux);
		cin >> aux;
	}
	Arbin<int> a = reconstruir(preorden, inorden, 0, preorden.size() - 1, 0, inorden.size() - 1);
	List<int>* l = a.niveles();

	if (preorden.size() > 0)
	{
		mostrar(l);
		cout << '\n';
	}

	return true;
}

int main()
{
	while (resuelveCaso());
	return 0;
}


