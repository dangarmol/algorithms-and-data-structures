#include<iostream>
#include <vector>

using namespace std;

int calcularMaximo(const vector<int> &apuestas) {
	int maximo = 0, contador = 0;
	for (int i = 0; i < apuestas.size(); ++i) {
		for (int j = i; j < apuestas.size(); ++j) {
			if (i == j) {
				contador = apuestas[i];
				if (apuestas[i] > maximo) maximo = apuestas[i];
			}
			else {
				contador += apuestas[j];
				if (contador > maximo) maximo = contador;
			}
		}
		contador = 0;
	}
	return maximo;
}

void resuelve(const int &n) {
	vector<int> apuestas;
	for (int i = 0; i < n; ++i) {
		int apuesta;

		cin >> apuesta;
		apuestas.push_back(apuesta);
	}
	int res = calcularMaximo(apuestas);
	if (res <= 0) cout << "Losing streak." << '\n';
	else cout << "The maximum winning streak is " << res << "." << '\n';
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