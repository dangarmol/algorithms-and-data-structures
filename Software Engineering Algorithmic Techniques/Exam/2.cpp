//Daniel Garcia Molero

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(size_t N) : size(N), _count(size), id(size, -1), biggest(-1) {}

	// devuelve el número de conjuntos disjuntos
	size_t count() const { return _count; }

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = int(buscar(id[p]));
	}

	// unir los conjuntos que contengan a p y q
	void unir(size_t p, size_t q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
			if (biggest > id[i]) {
				biggest = id[i];
			}
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			if (biggest > id[j]) {
				biggest = id[j];
			}
		}
		_count--;
	}

	int getBiggest() const {
		return this->biggest;
	}

protected:
	size_t size;             // los elementos son 0 .. size-1
	size_t _count;           // número de conjuntos disjuntos
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i
	int biggest;
};

//El coste de esta funcion sera el de los bucles for externos, que en el peor de los casos iteran n^2 veces,
//porque los bucles for internos tienen coste constante. Además, en muchas iteraciones de los bucles no se
//realizará ninguna funcion, ya que si no hay negro en la posicion consultada, se pasa a la siguiente.
//También hay que tener en cuenta que las operaciones de la clase ConjuntosDisjuntos tienen orden constante
//o incluso practicamente nulo, ya que en muchos casos, se llamará a la funcion unir, con conjuntos que ya estan
//unidos, por lo que la funcion simplemente retornara.
//Por lo tanto, el coste sera O(n^2), pero en la mayoria de los casos sera mucho menor.
void solveCase(const vector<vector<int>> &v, const int &rows, const int &cols) {
	ConjuntosDisjuntos cd = ConjuntosDisjuntos(rows * cols);
	int vacios = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (v[i][j] == 1) {
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						if ((k != 0 || l != 0) && k != l && k + i >= 0 && k + i < rows && l + j >= 0 && l + j < cols) {
							if (v[i][j] == v[i + k][j + l]) {
								cd.unir(i * cols + j, (i + k) * cols + j + l);
							}
						}
					}
				}
			} else {
				vacios++;
			}
		}
	}
	if (cd.count() == vacios)
		cout << cd.count() - vacios << " " << 0 << endl;
	else
		cout << cd.count() - vacios << " " << 0 - cd.getBiggest() << endl;
}

bool solve() {
	int rows, cols;
	string rowTaken;
	char aux;
	cin >> rows >> cols;
	if (!cin) return false;
	vector<vector<int>> matrix = vector<vector<int>>(rows, vector<int>(cols));
	for (size_t i = 0; i < rows; i++) {
		cin >> rowTaken;
		for (size_t j = 0; j < cols; j++) {
			if (rowTaken[j] == '-') {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
		}
	}
	solveCase(matrix, rows, cols);

	return true;
}

int main() {
	while (solve()) {}
	return 0;
}

/*
8 8
-#-#---#
-###---#
----####
-#------
-#-#----
-###-##-
###--##-
--#-----
4 10
#-#-#-###-
#-#-#-#-#-
#-#-#-#-#-
#-#-#-#-#-
*/