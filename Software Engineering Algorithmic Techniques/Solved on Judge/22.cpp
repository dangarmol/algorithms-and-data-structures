#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mayorAMenor(int a, int b) {
	if (a > b) return true;
	return false;
}

//El coste de la funcion voraz es del orden de O(n), donde n es el numero de elementos del vector local.
//Sin embargo, ya que se ordenan ambos vectores antes de entrar en esta funcion, el orden es:
//O(n * (log n)), donde n es el tamaño de los vectores local y visitante.
int vorazPuntos(const vector<int> &local, const vector<int> &visitante) {
	int maximo = 0;
	for (int i = 0; i < local.size(); ++i) {
		if (local[i] > visitante[i]) maximo += local[i] - visitante[i];
		else continue;
	}
	return maximo;
}

void resuelve(const int partidos) {
	vector<int> puntosLocal;
	vector<int> puntosRival;

	for (int i = 0; i < partidos; ++i) {
		int puntos;

		cin >> puntos;
		puntosRival.push_back(puntos);
	}
	for (int i = 0; i < partidos; ++i) {
		int puntos;

		cin >> puntos;
		puntosLocal.push_back(puntos);
	}
	sort(puntosLocal.begin(), puntosLocal.end(), mayorAMenor);
	sort(puntosRival.begin(), puntosRival.end());
	cout << vorazPuntos(puntosLocal, puntosRival) << '\n';
}

int main() {
	int partidos;

	cin >> partidos;
	while (partidos > 0) {
		resuelve(partidos);
		cin >> partidos;
	}
	return 0;
}
