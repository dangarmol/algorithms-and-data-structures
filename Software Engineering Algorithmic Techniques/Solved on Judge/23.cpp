#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mayorAMenor(int a, int b) {
	if (a > b) return true;
	return false;
}

int vorazCoches(const vector<int> &candidatos, const int v) {
	int j = candidatos.size() - 1, numCoches = 0;
	for (int i = 0; i < candidatos.size() && i < j; ++i) {
		while (candidatos[i] + candidatos[j] < v && i < j) {
			j--;
		}
		if (i < j) numCoches++;
		j--;
	}
	return numCoches;
}

void resuelve() {
	int pilas;

	cin >> pilas;
	int minVoltaje;
	vector<int> voltajes;

	cin >> minVoltaje;
	for (int i = 0; i < pilas; ++i) {
		int voltaje;

		cin >> voltaje;
		voltajes.push_back(voltaje);
	}
	sort(voltajes.begin(), voltajes.end(), mayorAMenor);
	cout << vorazCoches(voltajes, minVoltaje) << '\n';
}

int main() {
	int numCasos;

	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelve();
	}
	return 0;
}