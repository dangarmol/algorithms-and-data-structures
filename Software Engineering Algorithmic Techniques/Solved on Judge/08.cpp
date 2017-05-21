//Juan Alberto Camino Sáez
//Daniel Garcia
//Grupo 14
#include <iostream>

#include "PriorityQueue.h"

using namespace std;


void mostrarEspacio(const int &dato) {
	cout << dato << " ";
}

void mostrar(const int &dato) {
	cout << dato;
}

int calcularMediana(const PriorityQueue<int, std::greater<int>> &iz, const PriorityQueue<int> &dr, const int &numElems) {
	if (numElems % 2 == 0) {
		return iz.top() + dr.top();
	}
	else {
		return iz.top() * 2;
	}
}

//Esta funcion tiene un coste dentro de O(n * log(n)), siendo n el número de entradas, ya que hay un bucle for
//que da n vueltas que lee la entrada y con cada entrada
//las operaciones que realiza son push y pop, que en las colas de prioridad tienen coste logarítmico, y aunque llama
//a la función calcularMediana(), como solo hace top tiene coste constante.
void resuelve(const int &n) {
	PriorityQueue<int> colaMinimoMaximos; 
	PriorityQueue<int, std::greater<int>> colaMaximoMinimos;
	int dato;

	
	for (int i = 0; i < n; ++i) {
		cin >> dato;
		if ((i + 1) % 2 == 1) {
			colaMaximoMinimos.push(dato);
		}
		else {
			colaMinimoMaximos.push(dato);
		}
		if (i >= 2) {
			if (colaMaximoMinimos.top() > colaMinimoMaximos.top()) {
				int aux = colaMinimoMaximos.top();
				colaMinimoMaximos.pop();
				colaMinimoMaximos.push(colaMaximoMinimos.top());
				colaMaximoMinimos.pop();
				colaMaximoMinimos.push(aux);
			}
		}
		if (i + 1 == n) mostrar(calcularMediana(colaMaximoMinimos, colaMinimoMaximos, i + 1));
		else mostrarEspacio(calcularMediana(colaMaximoMinimos, colaMinimoMaximos, i + 1));
		
	}
	cout << endl;
}

int main() {
	int n;

	cin >> n;
	while (n != 0) {
		resuelve(n);
		cin >> n;
	}
	return 0;
}