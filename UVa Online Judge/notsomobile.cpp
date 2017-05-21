#include <iostream>
#include <fstream>

using namespace std;


int comprobar(bool &correcto) {
	int wr1, dr1, wl1, dl1;

	cin >> wr1 >> dr1 >> wl1 >> dl1;
	if (wr1 == 0) wr1 = comprobar(correcto);
	if (wl1 == 0) wl1 = comprobar(correcto);
	if (wr1 * dr1 != wl1 * dl1) correcto = false;
	return wr1 + wl1;
}

void resuelve(const int &contador, const int &n) {
	bool correcto = true;

	comprobar(correcto);
	if (correcto) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	if (contador != n - 1) cout << '\n';
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve(i, n);
	}
/*#ifndef DOMJUDGE
	std::ifstream in("casos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve(i, n);
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}