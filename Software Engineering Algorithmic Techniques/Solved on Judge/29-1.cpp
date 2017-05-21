//Juan Alberto Camino Sáez
//Daniel García Molero
//Grupo 14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Esta es la recurrencia usada en el ejercicio
int minDardos(vector<int> &sectores, int i, int j) {
	if (i == sectores.size() && j > 0) return 1000000;
	if (j == 0) return 0;
	if (sectores[i] > j) return minDardos(sectores, i + 1, j);
	else return min(minDardos(sectores, i + 1, j), 1 + minDardos(sectores, i, j - sectores[i]));
}

//El coste en tiempo y en espacio de esta funcion es O(n * c), ya que tenemos que recorrer la matriz para rellenar
//con los datos adecuados. n es el numero de sectores y c es la puntuación objetivo
vector<vector<int>> minDardos(vector<int> &sectores, int puntos) {
	int n = sectores.size() - 1;
	vector<vector<int>> matriz(n + 1, vector<int>(puntos + 1, 1000000));

	matriz[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		matriz[i][0] = 0;
		for (int j = 0; j <= puntos; ++j) {
			if (sectores[i] > j) matriz[i][j] = matriz[i - 1][j];
			else matriz[i][j] = min(matriz[i - 1][j], 1 + matriz[i][j - sectores[i]]);
		}
	}
	return matriz;
}

void mostrar(vector<vector<int>> &matriz, vector<int> sectores, int puntos) {
	if (matriz[matriz.size() - 1][puntos] == 1000000) {
		cout << "Imposible" << '\n';
		return;
	}
	cout << matriz[matriz.size() - 1][puntos] << ":" << " ";

	int resto = puntos, i = matriz.size() - 1;
	int c = matriz[matriz.size() - 1][puntos];
	while (resto > 0) {
		if (sectores[i] <= resto && matriz[i][resto] == 1 + matriz[i][resto - sectores[i]]) {
			if (c != 1) cout << sectores[i] << " ";
			else cout << sectores[i];
			resto = resto - sectores[i];
			c--;
		}
		else i--;
	}
	cout << '\n';
}

bool resuelve() {
	int puntos;

	cin >> puntos;
	if (!cin) return false;
	else {
		int numSectores;

		cin >> numSectores;
		vector<int> sectores(numSectores + 1);
		for (int i = 1; i <= numSectores; ++i) {
			cin >> sectores[i];
		}
		sort(sectores.begin(), sectores.end());
		vector<vector<int>> matriz = minDardos(sectores, puntos);
		mostrar(matriz, sectores, puntos);
		//cout << minimo << endl;
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}