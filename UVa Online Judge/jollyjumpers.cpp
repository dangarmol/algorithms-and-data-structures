#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class myVector {
private:
	vector<bool> numeros;
	int numMarcados;

public:
	myVector(const int &n) {
		numeros = vector<bool>(n, false);
		numMarcados = 0;
	}

	int getMarcados() const {
		return numMarcados;
	}

	bool marcar(const int &pos) {
		if (pos >= 0 && pos < numeros.size() && !numeros[pos]) {
			numMarcados++;
			numeros[pos] = true;
			return true;
		}
		return false;
	}

	bool esJolly() const {
		if (numMarcados == numeros.size())return true;
		return false;
	}
};

void comprobarJolly(const vector<int> &digitos, myVector &diferencias) {
	for (int i = 0; i < digitos.size() - 1; ++i) {
		if (!diferencias.marcar(abs(digitos[i] - digitos[i + 1]) - 1))break;
	}
}

bool resuelve() {
	int n;

	cin >> n;
	if (!cin) return false;
	else {
		myVector diferencias(n - 1);
		vector<int> digitos;

		for (int i = 0; i < n; ++i) {
			int num;

			cin >> num;
			digitos.push_back(num);
		}
		comprobarJolly(digitos, diferencias);
		if (diferencias.esJolly()) cout << "Jolly" << '\n';
		else cout << "Not jolly" << '\n';
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}