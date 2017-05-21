#include <iostream>

#include "PriorityQueue.h"

using namespace std;

long long int calcularCoste(PriorityQueue <long long int> &cola) {
	long long int total = 0, sumando1, sumando2, suma;

	while (cola.size() > 1) {
		sumando1 = cola.top();
		cola.pop();
		sumando2 = cola.top();
		cola.pop();
		suma = sumando1 + sumando2;
		total += suma;
		cola.push(suma);
	}

	return total;
}

void resuelve(const int &n) {
	PriorityQueue <long long int> cola;
	int dato;

	for (int i = 0; i < n; ++i) {
		cin >> dato;
		cola.push(dato);
	}
	cout << calcularCoste(cola) << '\n';

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