#include <iostream>
#include <vector>

using namespace std;

class myVector {
private:
	vector<bool> diasOcupados;
	int ocupados;

public:
	myVector(const int &n) {
		diasOcupados = vector<bool>(n, false);
		ocupados = 0;
	}

	int getOcupados() const {
		return ocupados;
	}

	void marcar(const int &pos, const int &semana) {
		if (!diasOcupados[pos] && (pos - 7 * semana) != 5 && (pos - 7 * semana) != 6) ocupados++;
		diasOcupados[pos] = true;
	}

};

int calcularDiasOcupados(const int &dias, const vector<int> &parties) {
	myVector ocupacion(dias);
	for (int i = 0; i < parties.size(); ++i) {
		int dia = parties[i] - 1;
		while (dia < dias) {
			ocupacion.marcar(dia, dia / 7);
			dia += parties[i];
		}
	}
	return ocupacion.getOcupados();
}

void resuelve() {
	vector<int> parties;
	int numParties, dias;

	cin >> dias >> numParties;
	for (int i = 0; i < numParties; ++i) {
		int h;

		cin >> h;
		parties.push_back(h);
	}

	cout << calcularDiasOcupados(dias, parties) << '\n';
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve();
	}
	return 0;
}