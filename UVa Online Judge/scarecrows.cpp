#include <iostream>
#include <vector>

using namespace std;

int minimoEspantapajaros(vector<bool> &campo, const vector<int> &fertiles) {
	int contador = 0;

	if (campo.size() == 0) return 0;
	else if (campo.size() == 1) {
		if (fertiles.size() > 0) return 1;
		else return 0;
	}
	else {
		for (int i = 0; i < fertiles.size(); ++i) {
			if (!campo[fertiles[i]]) {
				if (fertiles[i] + 1 < campo.size()) {
					if (fertiles[i] + 2 < campo.size()) campo[fertiles[i] + 2] = true;
					campo[fertiles[i] + 1] = true;
					campo[fertiles[i]] = true;
				}
				contador++;
			}
		}
	}

	return contador;
}

void resuelve(const int &caso) {
	vector<bool> campo;
	vector<int> fertiles;
	int dimension;

	cin >> dimension;
	for (int i = 0; i < dimension; ++i) {
		char c;

		cin >> c;
		campo.push_back(false);
		if (c == '.') fertiles.push_back(i);
	}
	cout << "Case " << caso << ": " << minimoEspantapajaros(campo, fertiles) << '\n';
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve(i + 1);
	}
	return 0;
}