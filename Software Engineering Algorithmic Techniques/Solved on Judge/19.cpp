#include <iostream>
#include <vector>

using namespace std;

int vorazParches(const vector<int> &candidatos, const int longitudParche) {
	int numParches = 1;
	/*int distanciaParche = 0 - longitudParche - 1;
	for (int i = 0; i < candidatos.size(); ++i) {
		if (candidatos[i] - longitudParche >= distanciaParche) {
			numParches++;
			distanciaParche = candidatos[i];
		}
	}*/
	if (candidatos.size() == 0) numParches = 0;
	else {
		int anterior = candidatos[0];
		for (int i = 1; i < candidatos.size(); ++i) {
			if (candidatos[i] - anterior > longitudParche) {
				numParches++;
				anterior = candidatos[i];
			}
		}
	}

	return numParches;
}

bool resuelve() {
	int agujeros;

	cin >> agujeros;
	if (!cin) return false;
	else {
		int parche;
		vector<int> posiciones;

		cin >> parche;
		for (int i = 0; i < agujeros; ++i) {
			int posicion;

			cin >> posicion;
			posiciones.push_back(posicion);
		}
		cout << vorazParches(posiciones, parche) << '\n';
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}