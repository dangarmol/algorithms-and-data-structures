#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

bool happyNumber(int &numero, unordered_map<int, bool> &numeros) {
	if (numeros.find(numero) != numeros.end()) return numeros[numero];
	else {
		numeros[numero] = false;
		vector<int> digitos;
		int aux = numero;
		while (aux != 0) {
			digitos.push_back(aux % 10);
			aux = aux / 10;
		}
		for (int i = 0; i < digitos.size(); ++i) {
			aux += digitos[i] * digitos[i];
		}
		bool happy = happyNumber(aux, numeros);
		numeros[numero] = happy;
		return happy;
	}
}

void resuelve(const int &caso, unordered_map<int, bool> &numeros) {
	int numero;

	cin >> numero;
	cout << "Case #" << caso << ": " << numero << " is ";
	if (happyNumber(numero, numeros)) cout << "a Happy number." << '\n';
	else cout << "an Unhappy number." << '\n';
}

int main() {
	int n;
	unordered_map<int, bool> numeros;

	numeros[1] = true;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve(i + 1, numeros);
	}

/*#ifndef DOMJUDGE
	std::ifstream in("casos2.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n;
	unordered_map<int, bool> numeros;

	numeros[1] = true;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve(i + 1, numeros);
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}