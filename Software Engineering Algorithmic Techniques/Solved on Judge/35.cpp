//Juan Alberto Camino Sáez
//Daniel García Molero
//Grupo 14
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*int palindromo(const string &palabra, int i, int j, vector<char> &solucion) {
	if (i >= j) {
		if (i == j) return 1;
		else return 0;
	}
	else if (palabra[i] == palabra[j]) return 2 + palindromo(palabra, i + 1, j - 1, solucion);
	else return max(palindromo(palabra, i + 1, j, solucion), palindromo(palabra, i, j - 1, solucion));
}*/

/*int palindromo(const string &palabra, vector<char> &solucion) {
	vector<vector<int>> matriz(palabra.size(), vector<int>(palabra.size(), 0));

	for (int i = 0; i < palabra.size(); ++i) {
		matriz[i][i] = 1;
	}
	for (int i = 1; i < palabra.size(); ++i) {
		int k = 0;
		for (int j = i; j < palabra.size(); ++j) {
			if (palabra[k] == palabra[j]) matriz[k][j] = 2 + matriz[k + 1][j - 1];
			else matriz[k][j] = max(matriz[k][j - 1], matriz[k + 1][j]);
			k++;
		}
	}
	for (int i = 0; i < palabra.size(); ++i) {
		for (int j = 0; j < palabra.size(); ++j) {
			if (j == palabra.size() - 1) cout << matriz[i][j] << endl;
			else cout << matriz[i][j] << " ";
		}
	}
	int mitad = (palabra.size() - 1) / 2;
	int pos = 0;
	for (int i = mitad; i < palabra.size() - 1; ++i) {
		if (matriz[i][i] != matriz[i + 1][i + 1]) {
			solucion.push_back(palabra[pos]);
		}
		pos++;
	}
	solucion.push_back(palabra[pos]);
	
	return matriz[0][palabra.size() - 1];
	return 0;
}*/

//La recurrencia usada en este ejercicio es la siguiente:
// palindromo (i, j) = {
//		0 si i > j
//		1 si i == j
//		2 + palindromo(i + 1, j - 1) si letras[i] == letras[j]
//		max(palindromo(i + 1, j), palindromo(i, j - 1) si letras[i] != letras[j]
//	}
//El coste en tiempo es O(n^2), aunque en realidad la mitad de la tabla la tienes rellena desde el principio
//el coste en espacio es O(n^2), aunque si no se pidiera la palabra palindroma podría reducirse a O(n)
// n es el tamaño de la palabra de la que se quiere sacar el palindromo
string palindromo(const string &palabra) {
	vector<vector<int>> matriz(palabra.size(), vector<int>(palabra.size(), 0));

	for (int i = 0; i < palabra.size(); ++i) {
		matriz[i][i] = 1;
	}
	for (int i = 1; i < palabra.size(); ++i) {
		int k = 0;
		for (int j = i; j < palabra.size(); ++j) {
			if (palabra[k] == palabra[j]) matriz[k][j] = 2 + matriz[k + 1][j - 1];
			else matriz[k][j] = max(matriz[k][j - 1], matriz[k + 1][j]);
			k++;
		}
	}
	/*for (int i = 0; i < palabra.size(); ++i) {
		for (int j = 0; j < palabra.size(); ++j) {
			if (j == palabra.size() - 1) cout << matriz[i][j] << endl;
			else cout << matriz[i][j] << " ";
		}
	}*/
	string solucion("",matriz[0][palabra.size() - 1]);
	
	int l = 0, j = palabra.size() - 1, pos = solucion.size() - 1;
	bool parar = false;
	bool paso = false;

	while (!parar) {
		if (l >= j) {
			parar = true;
			if (l == j) solucion[pos] = palabra[l];
		}
		else if (palabra[l] == palabra[j]) {
			solucion[pos] = palabra[l];
			solucion[solucion.size() - 1 - pos] = palabra[l];
			pos--;
			l++;
			j--;
		}
		else {
			if (matriz[l + 1][j] >= matriz[l][j - 1]) {
				l++;
			}
			else {
				j--;
			}
		}
	}

	return solucion;
}

bool resuelve() {
	string palabra;

	cin >> palabra;
	if (!cin) return false;
	else {
		vector<char> solucion;
		cout << palindromo(palabra) << endl;
		return true;
	}

}

int main() {
	while (resuelve()) {}
	return 0;
}