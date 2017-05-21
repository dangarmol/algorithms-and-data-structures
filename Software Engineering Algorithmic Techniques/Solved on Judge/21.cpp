#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vorazEsquiadores(const vector<int> &alturas, const vector<int> &esquies) {
	/*int totalAlturas = 0, totalEsquies = 0;
	for (int i = 0; i < alturas.size(); ++i) {
		if (alturas[i] > esquies[i]) {
			totalAlturas += alturas[i];
			totalEsquies += esquies[i];
		}
		else {
			totalAlturas += esquies[i];
			totalEsquies += alturas[i];
		}
	}
	return totalAlturas - totalEsquies;*/
	int minimo = 0;
	for (int i = 0; i < alturas.size(); ++i) {
		minimo += abs(alturas[i] - esquies[i]);
	}
	return minimo;
}

void resuelve(const int esquiadores) {
	vector<int> alturas;
	vector <int> esquies;

	for (int i = 0; i < esquiadores; ++i) {
		int altura;
		
		cin >> altura;
		alturas.push_back(altura);
	}
	for (int i = 0; i < esquiadores; ++i) {
		int esqui;

		cin >> esqui;
		esquies.push_back(esqui);
	}
	sort(alturas.begin(), alturas.end());
	sort(esquies.begin(), esquies.end());
	cout << vorazEsquiadores(alturas, esquies) << '\n';
}

int main() {
	int esquiadores;

	cin >> esquiadores;
	while (esquiadores != 0) {
		resuelve(esquiadores);
		cin >> esquiadores;
	}
	return 0;
}