#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Par {
private:
	int x;
	int y;

public:
	Par(int x1, int y1) {
		x = x1;
		y = y1;
	}

	int getX() const {
		return x;
	}

	int getY() {
		return y;
	}
};

void actualizarTablero(int x, int y, vector<vector<int>> &tablero, int dimx, int dimy) {
	for (int i = x - 1; i <= x + 1; ++i) {
		for (int j = y - 1; j <= y + 1; ++j) {
			if (i >= 0 && i < dimx && j >= 0 && j < dimy) {
				if (tablero[i][j] != -1)tablero[i][j]++;
			}
		}
	}
}

bool resuelve(const int &contador) {
	int x, y;

	cin >> x >> y;
	if (x == 0 || y == 0) return false;
	else {
		if (contador != 1) cout << '\n';
		vector<Par> minas;
		vector<vector<int>> tablero(x, vector<int>(y));

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				char pos;

				cin >> pos;
				if (pos == '*') {
					tablero[i][j] = -1;
					minas.push_back(Par(i, j));
				}
				else tablero[i][j] = 0;
			}
		}

		for (int i = 0; i < minas.size(); ++i) {
			actualizarTablero(minas[i].getX(), minas[i].getY(), tablero, x, y);
		}

		cout << "Field #" << contador << ":" << '\n';
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				if (tablero[i][j] == -1) {
					if (j == y - 1) cout << '*' << '\n';
					else cout << '*';
				}
				else {
					if (j == y - 1) cout << tablero[i][j] << '\n';
					else cout << tablero[i][j];
				}
			}
		}
		return true;
	}
}

int main() {
	
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	long long int contador = 1;

	while (resuelve(contador)) {
		contador++;
	}
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	long long int contador = 1;

	while (resuelve(contador)) {
		contador++;
	}
	return 0;
}