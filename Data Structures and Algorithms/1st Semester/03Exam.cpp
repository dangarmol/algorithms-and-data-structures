//Daniel Garcia Molero
//Pto0512
//Usuario juez "F38"
//Todo funciona

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int AZUL = 0, ROJO = 1, VERDE = 2;

void tratarSolucion(const vector<string> &sol, const int &n) {
	for (size_t i = 0; i < n; i++) {
		cout << sol[i] << " ";
	}
	cout << endl;
}

bool esSolucion(const int &heigth, const int &n, const vector<int> &colorCounter) {
	return heigth == n && (colorCounter[ROJO] > colorCounter[AZUL] + colorCounter[VERDE]);
}

bool esValida(const int &n, const vector<string> &sol, const int &a, const int &r, const int &v, const int &h, const vector<int> &colorCounter) {
	if (sol[0] != "rojo") return false;
	else if (n <= h) return false;
	else if (h > 1 && sol[h] == "verde" && sol[h - 1] == "verde") return false;
	else if (colorCounter[AZUL] > a || colorCounter[ROJO] > r || colorCounter[VERDE] > v) return false;
	else if (colorCounter[VERDE] > colorCounter[AZUL]) return false;
	return true;
}

void towers(const int &n, const int &aMax, const int &rMax, const int &vMax, vector<int> colorCounter, vector<string> sol, const int &h, const string colors[], bool &thereIsSol) {
	if (n <= h) return;
	for (size_t i = AZUL; i <= VERDE; i++) {
		sol[h] = colors[i];
		colorCounter[i]++;
		if (esValida(n, sol, aMax, rMax, vMax, h, colorCounter)) {
			if (esSolucion(h + 1, n, colorCounter)) {
				thereIsSol = true;
				tratarSolucion(sol, n);
			} else {
				towers(n, aMax, rMax, vMax, colorCounter, sol, h + 1, colors, thereIsSol);
			}
		}
		colorCounter[i]--;
	}
}

bool solve() {
	string colors[3] = {"azul", "rojo", "verde"};
	bool thereIsSol = false;
	vector<int> colorCounter(3, 0);
	int n, a, r, v, heigth = 0;
	cin >> n >> a >> r >> v;
	if (n == 0 && a == 0 && r == 0 && v == 0) return false;
	vector<string> sol(n);
	towers(n, a, r, v, colorCounter, sol, heigth, colors, thereIsSol);
	if (!thereIsSol) {
		cout << "SIN SOLUCION" << endl;
	}
	return true;
}

int main() {
	while (solve()) {}
	return 0;
}