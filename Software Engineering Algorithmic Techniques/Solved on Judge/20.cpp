#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool mayorAMenor(int a, int b) {
	if (a > b) {
		return true;
	}
	return false;
}

int vorazDescuento(vector <int> &solucion, const vector<int> &candidatos) {
	int mayorDescuento = 0;
	
	for (int i = 2; i < candidatos.size(); i = i + 3) {
		solucion.push_back(candidatos[i]);
		mayorDescuento += candidatos[i];
	}
	return mayorDescuento;
}


//El coste total de este algoritmo es O(n * (log n)), siendo n el numero de libros que se compren.
//Esto es debido a la funcion sort antes de llamar al algoritmo voraz.
//Si solo contamos el coste de la funcion vorazDescuento(), el coste seria O(n)
bool resuelve() {
	int libros;

	cin >> libros;
	if (!cin) return false;
	else {
		vector<int> precios;
		for (int i = 0; i < libros; ++i) {
			int precio;

			cin >> precio;
			precios.push_back(precio);
		}
		vector<int> solucion;
		sort(precios.begin(), precios.end(), mayorAMenor);
		cout << vorazDescuento(solucion, precios) << '\n';
		return true;
	}
}
int main() {
	while (resuelve()) {}
	return 0;
}
