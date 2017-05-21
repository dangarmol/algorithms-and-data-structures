#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Cofre {
private:
	int profundidad;
	int oro;

public:
	Cofre(int p, int o) {
		profundidad = p;
		oro = o;
	}

	int getProfundidad() const {
		return profundidad;
	}

	int getOro() const {
		return oro;
	}

	bool operator<(const Cofre &otro) const {
		if (oro < otro.oro) return true;
		else return false;
	}
};

/*class myVector {
private:
	vector <Cofre> cofres;
public:
	myVector(vector <Cofre> &c) {
		cofres = c;
		sort(cofres.begin(), cofres.end());
	}

	int contains(int numero) {
		int contador = 0;

		for (int i = 0; i < cofres.size(); ++i) {
			if (cofres[i].getOro() == numero) contador++;
			else if (cofres[i].getOro() > numero) break;
		}
		return contador;
	}
};*/

/*int maxOro(const vector<Cofre> &cofres, const int cofre, const int segundos) {
	if (cofre >= cofres.size()) return 0;
	else {
		if (cofre >= cofres.size() || cofres[cofre].getProfundidad() * 3 >= segundos) return maxOro(cofres, cofre + 1, segundos);

		int cogerlo = cofres[cofre].getOro() + maxOro(cofres, cofre + 1, segundos - 3 * cofres[cofre].getProfundidad());
		int dejarlo = maxOro(cofres, cofre + 1, segundos);
		return max(cogerlo, dejarlo);
	}
}*/

/*int maxOro(const vector<Cofre> &cofres, const int segundos, vector<bool> &cogidos) {
	vector<vector<int>> matriz(cofres.size(), vector<int> (segundos));

	for (int i = 0; i < segundos; ++i) {
		if (3 * cofres[0].getProfundidad() < i + 1) matriz[0][i] = cofres[0].getOro();
		else matriz[0][i] = 0;
	}
	for (int i = 1; i < cofres.size(); ++i) {
		for (int j = 0; j < segundos; ++j) {
			if ((j + 1) - 3 * cofres[i].getProfundidad() <= 0) matriz[i][j] = matriz[i - 1][j];
			else {
					matriz[i][j] = max(matriz[i - 1][j], matriz[i - 1][j - 3 * cofres[i].getProfundidad()] + cofres[i].getOro());
			}
		}
	}

	return matriz[cofres.size() - 1][segundos - 1];
}*/

vector<int> maxOro(const vector<Cofre> &cofres, const int segundos, vector<bool> &cogidos) {
	vector<int> matriz(segundos);
	for (int i = 0; i < segundos; ++i) {
		if (3 * cofres[0].getProfundidad() < i + 1) matriz[i] = cofres[0].getOro();
		else matriz[i] = 0;
	}
	for (int i = 1; i < cofres.size(); ++i) {
		for (int j = segundos - 1; j >= 0; --j) {
			if ((j + 1) - 3 * cofres[i].getProfundidad() > 0)
				matriz[j] = max(matriz[j], matriz[j - 3 * cofres[i].getProfundidad()] + cofres[i].getOro());
		}
	}

	/*for (int i = 0; i < matriz.size(); ++i) {
		cout << matriz[i] << " ";
	}
	cout << endl;*/

	return matriz;
}

void mostrarCofres(vector<int> &solucion, vector<Cofre> &cofres) {
	cout << solucion[solucion.size() - 1] << '\n';
}

bool resuelve() {
	int segundos;

	cin >> segundos;
	if (!cin) return false;
	else {
		int ncofres;
		vector<Cofre> cofres;

		cin >> ncofres;
		vector<bool> cogidos(ncofres, false);

		for (int i = 0; i < ncofres; ++i) {
			int profundidad, oro;

			cin >> profundidad >> oro;
			cofres.push_back(Cofre(profundidad, oro));
		}
		/*int total = maxOro(cofres, segundos, cogidos);
		cout << total << '\n';*/
		mostrarCofres(maxOro(cofres, segundos, cogidos), cofres);
		return true;
	}

	
}

int main() {
	while (resuelve()) {}
	return 0;
}
