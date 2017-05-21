#include <iostream>
#include <vector>

using namespace std;

void resuelve(const int n) {
	vector<int> codigos;
	int codigo;

	for (int i = 0; i < n; ++i) {
		int cod;

		cin >> cod;
		codigos.push_back(cod);
	}

	cin >> codigo;
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