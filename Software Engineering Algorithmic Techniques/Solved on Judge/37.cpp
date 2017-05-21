//Juan Alberto Camino Sáez
//Daniel García Molero
//Grupo 14
#include <iostream>
#include <vector>

using namespace std;

//Para resolver este ejercicio hemos usado la función de combinatorios, y calculamos todos a la vez
//La funcion de los combinatorios es de O(n^2), mientras que calcular las posiciones es O(n)
//En cambio, una vez calculado el numero de resultados de un numero, saber los de por debajo de el se puede hacer
//con coste constante
void calcularCaracoles(vector<int> &solucion, const vector <vector<int>> &c) {
	solucion[0] = 0;
	solucion[1] = 1;
	for (int i = 1; i <= 1000; ++i) {
		int suma = 1;
		for (int j = i - 1; j >= 1; --j) {
			int k;
			if (j > i / 2) k = i - j;
			else k = j;
			suma = (suma + ((c[i][k] * solucion[j]) % 46337)) % 46337;
		}
		solucion[i] = suma;
	}
}

void combinatorio(vector <vector<int>> &C, int n, int r) {
	C[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= r; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 46337;
		}
	}
}

bool resuelve(const vector<int> &solucion) {
	int n;

	cin >> n;
	if (!cin) return false;
	else {
		cout << solucion[n] << '\n';
	}
}

int main() {
	vector <vector<int>> combinatorios(1001, vector<int>(501, 0));
	vector<int> solucion(1001);

	combinatorio(combinatorios, 1000, 500);
	calcularCaracoles(solucion, combinatorios);
	while (resuelve(solucion)) {}
	return 0;
}