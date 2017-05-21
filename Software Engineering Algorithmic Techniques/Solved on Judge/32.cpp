#include <iostream>
#include <vector>

using namespace std;

void floyd(vector<vector<int>> &G, vector<vector<int>> &C, vector<vector<int>> &camino) {
	int n = G.size() - 1;
	C = G;
	camino = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int t = C[i][k] + C[k][j];
				if (t < C[i][j]) {
					C[i][j] = t;
					camino[i][j] = k;
				}
			}
		}
	}
}

bool resuelve() {
	int poblados;
	
	cin >> poblados;
	if (!cin) return false;
	else {
		vector<vector<int>> matriz(poblados + 1, vector<int>(poblados + 1, 1000000));

		for (int i = 1; i <= poblados; ++i) {
			for (int j = i; j <= poblados; ++j) {
				if (i == j) matriz[i][j] = 0;
				else cin >> matriz[i][j];
			}
		}
		/*for (int k = 1; k < matriz.size(); ++k) {
			for (int i = 1; i < matriz.size(); ++i) {
				if (matriz[k][i] != 1000000) {
					if (i != matriz.size() - 1) cout << matriz[k][i] << " ";
					else cout << matriz[k][i] << endl;
				}
				else {
					if (i != matriz.size() - 1) cout << "a" << " ";
					else cout << "a" << endl;
				}
			}
		}*/
		vector<vector<int>> C(0, vector<int>(0));
		vector<vector<int>> camino(0, vector<int>(0));
		floyd(matriz, C, camino);
		cout << endl;
		for (int i = 1; i < C.size(); ++i) {
			for (int j = i + 1; j < C.size(); ++j) {
				if (j != C.size() - 1) cout << C[i][j] << " ";
				else cout << C[i][j] << '\n';
			}
		}
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}