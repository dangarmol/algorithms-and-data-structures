#include <iostream>
#include <vector>

using namespace std;

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(size_t N) : size(N), _count(size), id(size, -1) {}

	// devuelve el número de conjuntos disjuntos
	size_t count() const { return _count; }

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = int(buscar(id[p]));
	}

	int buscarTamanio(size_t p) const {
		if (id.at(p) < 0) // es una raíz
			return 0 - id.at(p);
		else
			return buscarTamanio(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	void unir(size_t p, size_t q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
		}
		_count--;
	}

	void buscarMayor() {
		mayor = 0;
		segundoMayor = 0;
		for (int i = 0; i < id.size(); ++i) {
			if (id[i] < 0) {
				if (0 - id[i] > mayor) {
					segundoMayor = mayor;
					mayor = 0 - id[i];
				}
				else if (0 - id[i] > segundoMayor) segundoMayor = 0 - id[i];
			}
		}
	}

	int buscarSiguiente(size_t p) const {
		return id[p];
	}

	int getMayor() const {
		return mayor;
	}

	int getSegundoMayor() const {
		return segundoMayor;
	}

	// muestra el array por la salida o 
	void print(std::ostream& o = std::cout) const {
		o << _count << ": ";
		for (auto i = 0; i < size; ++i)
			o << id[i] << " ";
	}

protected:
	size_t size;             // los elementos son 0 .. size-1
	size_t _count;           // número de conjuntos disjuntos
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i
	int mayor;
	int segundoMayor;

};

inline std::ostream& operator<<(std::ostream & o, ConjuntosDisjuntos const& a) {
	a.print(o);
	return o;
}

void comprobarAlrededores(ConjuntosDisjuntos &c, const vector<vector<char>> &mapa, int &k, int &l, int &dimx, int &dimy, const char &tierra) {
	for (int i = k - 1; i <= k + 1; ++i) {
		for (int j = l - 1; j <= l + 1; ++j) {
			if (i >= 0 && i < dimx) {
				int aux = j;
				if (aux == -1) aux = dimy - 1;
				if (aux == dimy) aux = 0;
				if ((k == i || l == aux) && i != aux) {
					if (mapa[i][aux] == tierra) c.unir(i * dimy + aux, k * dimy + l);
				}
			}
		}
	}
}

int calcularMayorRegion(const vector<vector<char>> &mapa, int &dimx, int &dimy, int posrey, const char &tierra) {
	ConjuntosDisjuntos c(dimx * dimy);
	vector<int> land;

	for (int i = 0; i < dimx; ++i) {
		for (int j = 0; j < dimy; ++j) {
			if (mapa[i][j] == tierra) {
				comprobarAlrededores(c, mapa, i, j, dimx, dimy, tierra);
				land.push_back(i * dimy + j);
			}
		}
	}
	if (c.count() == 1 || land.size() == 1) return 0;
	bool uncontinente = true, unNegativo = false, b = false;
	int i = 0, anterior;
	for (i; i < land.size(); ++i) {
		if (c.buscarSiguiente(land[i]) >= 0) {
			anterior = c.buscarSiguiente(land[i]);
			i++;
			break;
		}
		else {
			if(!unNegativo) unNegativo = true;
			else {
				uncontinente = false;
				i = land.size();
			}
		}
	}
	if (i != land.size()) b = true;
	for (i; i < land.size(); ++i) {
		if (c.buscarSiguiente(land[i]) < 0) {
			if (!unNegativo) unNegativo = true;
			else {
				uncontinente = false;
				break;
			}
		}
		else if (c.buscarSiguiente(land[i]) != anterior) {
			uncontinente = false;
			break;
		}
	}
	if (uncontinente && b) return 0;
	c.buscarMayor();
	if (c.buscarTamanio(posrey) == c.getMayor()) return c.getSegundoMayor();
	return c.getMayor();

}

bool resuelve() {
	int x;

	cin >> x;
	if (!cin) return false;
	else {
		int y;

		cin >> y;
		vector<vector<char>> mapa(x, vector<char>(y));

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				char c;

				cin >> c;
				mapa[i][j] = c;
			}
		}
		int xr, yr;

		cin >> xr >> yr;
		cout << calcularMayorRegion(mapa, x, y, (xr * y + yr), mapa[xr][yr]) << '\n';
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}