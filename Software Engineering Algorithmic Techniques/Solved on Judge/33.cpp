//Juan Alberto Camino Sáez
//Daniel García Molero
//Grupo 14
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int calcularMaximo(const vector<vector<int>> & camino) {
	int maximo = -1;
	for (int i = 1; i < camino.size(); ++i) {
		for (int j = 1; j < camino[i].size(); ++j) {
			/*if (j != camino.size() - 1) cout << camino[i][j] << " ";
			else cout << camino[i][j] << endl;*/
			if (camino[i][j] > maximo) maximo = camino[i][j];
		}
	}

	return maximo;
}

//Para resolver este ejercicio hemos usado el algoritmo de floyd para calcular los caminos minimos
//El coste en tiempo es O(n^3), mientras que en espacio es O(n^2), siendo n el numero de personas
int floyd(vector<vector<int>> const& G, vector<vector<int>> & C, vector<vector<int>> & camino) {
	size_t n = G.size() - 1;
	// inicialización
	C = G;
	camino = vector<vector<int>> (n + 1,vector<int>(n + 1, 0));

	// actualizaciones de la matriz
	for (size_t k = 1; k <= n; ++k) {
		for (size_t i = 1; i <= n; ++i) {
			for (size_t j = 1; j <= n; ++j) {
				int temp = C[i][k] + C[k][j];
				if (temp < C[i][j]) { // es mejor pasar por k
					C[i][j] = temp;
					camino[i][j] = k;
				}
			}
		}
	}
	return calcularMaximo(C);
	/*for (int i = 0; i < C.size(); ++i) {
		for (int j = 0; j < C.size(); ++j) {
			if (j != C.size() - 1) cout << C[i][j] << " ";
			else cout << C[i][j] << endl;
		}
	}*/
}

bool resuelve() {
	int npersonas;
	const int INFINITO = 1000000000;

	cin >> npersonas;
	if (!cin) return false;
	else {
		int relaciones, pos = 1;
		vector<vector<int>> grafo(npersonas + 1, vector<int>(npersonas + 1, INFINITO));
		unordered_map <string, int> personas;

		cin >> relaciones;
		for (int i = 1; i <= npersonas; ++i) {
			grafo[i][i] = 0;
		}
		string u, v;

		for (int i = 1; i <= relaciones; ++i) { // leer aristas
			cin >> u >> v;
			if (personas.find(u) == personas.end()) {
				personas[u] = pos;
				pos++;
			}
			if (personas.find(v) == personas.end()) {
				personas[v] = pos;
				pos++;
			}

			grafo[personas[u]][personas[v]] = 1;
			grafo[personas[v]][personas[u]] = 1;
		}
		vector<vector<int>> C(0, vector<int>(0)), camino(0, vector<int>(0));
		
		int maximo = floyd(grafo, C, camino);
		if (maximo == INFINITO) {
			cout << "DESCONECTADA" << '\n';
		}
		else {
			cout << maximo << '\n';
		}

		return true;
	}

}

int main() {
	while (resuelve()) {}
	return 0;
}