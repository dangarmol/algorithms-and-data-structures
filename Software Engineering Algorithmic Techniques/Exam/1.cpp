//Daniel Garcia Molero

#include <iostream>
#include "PriorityQueue.h"
using namespace std;

//La estrategia que he seguido es ir cambiando de equipo al minimo numero de seguidores cada vez
//De manera que el coste del cambio sea el minimo
//La solucion tiene un coste del orden de O(n*log(n)) en funcion de "n" siendo el numero de equipos,
//ya que es lo que define el numero de iteraciones del bucle while, y teniendo en cuenta que el coste de
//las operaciones excepto el top (que es constante), tienen coste log(n), queda dicho coste: O(n*log(n))
long long getNumGorras(PriorityQueue<long long> &pq) {
	long long costeGorras = 0, a, b;
	while (pq.size() > 1) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		costeGorras += a;
		costeGorras += b;
		pq.push(a + b);
	}
	return costeGorras;
}

bool solve() {
	int nEquipos, aux;
	PriorityQueue<long long> pq;
	cin >> nEquipos;
	if (nEquipos == 0) return false;
	for (size_t i = 0; i < nEquipos; i++) {
		cin >> aux;
		pq.push(aux);
	}
	cout << getNumGorras(pq) << endl;
	return true;
}

int main() {
	while (solve()){}
	return 0;
}