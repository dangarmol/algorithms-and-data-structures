#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Varilla {
public:
	int longitud;
	int coste;

	Varilla() {}
	Varilla(int l, int c) {
		longitud = l;
		coste = c;
	}

	bool operator< (const Varilla &otro) const {
		return longitud < otro.longitud;
	}
};

bool mayorque(const Varilla &a, const Varilla &b) {
	return a.coste > b.coste;
}

int minVarillas(const vector<Varilla> &varillas, int i, int j) {
	if (i == varillas.size() && j > 0) return 1000000;
	if (j == 0) return 0;
	if (varillas[i].longitud > j) return minVarillas(varillas, i + 1, j);
	else return min(minVarillas(varillas, i + 1, j), 1 + minVarillas(varillas, i + 1, j - varillas[i].longitud));
}

int posibilidades(const vector<Varilla> &varillas, int i, int j) {
	if (i == varillas.size() && j > 0) return 0;
	if (j == 0) return 1;
	if (varillas[i].longitud > j) return posibilidades(varillas, i + 1, j);
	else return posibilidades(varillas, i + 1, j) + posibilidades(varillas, i + 1, j - varillas[i].longitud);
}

/*5 10
2 5
3 60
5 40
1 20
4 15*/

/*void minVarillas(const vector<Varilla> &varillas, int longitud, vector<vector<int>> &matriz, vector<vector<int>> &costes, vector<vector<int>> &maneras) {
	int n = varillas.size() - 1;
	matriz = vector<vector<int>>(n + 1, vector<int>(longitud + 1, 1000000));
	costes = vector<vector<int>>(n + 1, vector<int>(longitud + 1, 1000000));
	maneras = vector<vector<int>>(n + 1, vector<int>(longitud + 1, 0));

	matriz[0][0] = 0;
	costes[0][0] = 0;
	maneras[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		matriz[i][0] = 0;
		costes[i][0] = 0;
		maneras[i][0] = 1;
		for (int j = 1; j <= longitud; ++j) {
			if (varillas[i].longitud > j) {
				matriz[i][j] = matriz[i - 1][j];
				costes[i][j] = costes[i - 1][j];
				maneras[i][j] = maneras[i - 1][j];
			}
			else {
				matriz[i][j] = min(matriz[i - 1][j], 1 + matriz[i - 1][j - varillas[i].longitud]);
				costes[i][j] = min(costes[i - 1][j], varillas[i].coste + costes[i - 1][j - varillas[i].longitud]);
				maneras[i][j] = maneras[i - 1][j] + maneras[i - 1][j - varillas[i].longitud];
			}
		}
	}
}*/
void minVarillas(const vector<Varilla> &varillas, int longitud, vector<int> &matriz, vector<int> &costes, vector<int> &maneras) {
	int n = varillas.size() - 1;
	matriz = vector<int>(longitud + 1, 1000000);
	vector<int> matrizanterior(longitud + 1, 1000000);
	costes = vector<int>(longitud + 1, 1000000);
	vector<int> canterior(longitud + 1, 1000000);
	maneras = vector<int>(longitud + 1, 0);
	vector<int> manterior(longitud + 1, 0);

	matrizanterior[0] = 0;
	canterior[0] = 0;
	manterior[0] = 1;
	for (int i = 1; i <= n; ++i) {
		matriz[0] = 0;
		costes[0] = 0;
		maneras[0] = 1;
		for (int j = 1; j <= longitud; ++j) {
			if (varillas[i].longitud <= j) {
				matriz[j] = min(matrizanterior[j], matrizanterior[j - varillas[i].longitud] + 1);
				costes[j] = min(canterior[j], canterior[j - varillas[i].longitud] + varillas[i].coste);
				maneras[j] = manterior[j] + manterior[j - varillas[i].longitud];
			}
			else {
				matriz[j] = matrizanterior[j];
				costes[j] = canterior[j];
				maneras[j] = manterior[j];
			}
		}
		matrizanterior = matriz;
		canterior = costes;
		manterior = maneras;
	}
}

bool resuelve() {
	int nvarillas;

	cin >> nvarillas;
	if (!cin) return false;
	else {
		int longitud, contador;
		vector<Varilla> varillas(nvarillas + 1);
		vector<int> costes;
		vector<int> matriz;
		vector<int> maneras;
		/*vector<vector<int>> costes;
		vector<vector<int>> matriz;
		vector<vector<int>> maneras;*/

		cin >> longitud;
		for (int i = 1; i < varillas.size(); ++i) {
			cin >> varillas[i].longitud >> varillas[i].coste;
		}
		sort(varillas.begin() + 1, varillas.end());
		minVarillas(varillas, longitud, matriz, costes, maneras);
		/*for (int i = 0; i < matriz.size(); ++i) {
			for (int j = 0; j < matriz[i].size(); ++j) {
				if (matriz[i][j] == 1000000) {
					if (j != matriz[i].size() - 1) cout << "a" << " ";
					else cout << "a" << endl;
				}
				else {
					if (j != matriz[i].size() - 1) cout << matriz[i][j] << " ";
					else cout << matriz[i][j] << endl;
				}

			}
		}*/
		/*if (matriz[matriz.size() - 1][matriz[0].size() - 1] == 1000000) {
			cout << "NO" << '\n';
		}
		else {
			cout << "SI" << " " << maneras[maneras.size() - 1][maneras[0].size() - 1] << " " << matriz[matriz.size() - 1][matriz[0].size() - 1] << " " << costes[costes.size() - 1][costes[0].size() - 1] << '\n';
		}*/
		if (matriz[matriz.size() - 1] == 1000000) {
			cout << "NO" << '\n';
		}
		else {
			cout << "SI" << " " << maneras[maneras.size() - 1] << " " << matriz[matriz.size() - 1] << " " << costes[costes.size() - 1] << '\n';
		}
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}