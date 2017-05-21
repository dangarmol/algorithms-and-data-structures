#include <iostream>
#include <unordered_map>

using namespace std;

void cycles(const int &n, int &contador, unordered_map<int, int> &resultados) {
	if (resultados.find(n) != resultados.end()) {
		contador = resultados[n];
	}
	else {
		if (n % 2 == 0) cycles(n / 2, contador, resultados);
		else cycles(3 * n + 1, contador, resultados);
		contador++;
		resultados[n] = contador;
	}
}

bool resuelve(unordered_map<int, int> &resultados) {
	int n1;
	bool reves = false;

	cin >> n1;
	if (!cin) return false;
	else {
		int n2, maximo = 0, contador;

		cin >> n2;
		if (n2 < n1) {
			int tmp = n1;
			n1 = n2;
			n2 = tmp;
			reves = true;
		}
		for (int i = n1; i <= n2; ++i) {
			cycles(i, contador, resultados);
			if (maximo <= contador) {
				maximo = contador;
			}
		}
		if (!reves) cout << n1 << " " << n2 << " " << maximo << '\n';
		else cout << n2 << " " << n1 << " " << maximo << '\n';
		
		return true;
	}
}

int main() {
	unordered_map<int, int> resultados;

	resultados[1] = 1;
	while (resuelve(resultados)) {}
	return 0;
}