//Daniel Garcia Molero
//Pto0512
//Usuario juez "F38"
//Todo funciona

#include <iostream>
#include <vector>
using namespace std;

/*
1.-
P = (n = e.size() ^ n >= 0 ^ (paratodo p : 0 <= p < n : e[p] > 0))
fun removeOdds(int &e[], int n) return int k
Q = ((k = (#l : 0 <= l < n : e[l]%2 = 0)) ^ (paratodo j : 0 <= j < k : e[j] % 2 = 0))

3.- Invariante:
I = ((0 <= i <= n) ^ (k = (#x : 0 <= x <= i : e[x] % 2 = 0)) ^ (paratodo y : 0 <= y < k : e[k] % 2 = 0))
El bucle finalizara cuando la i tome el valor de n, es decir, que se haya superado el tamano del array y no
se vaya a poder acceder a este.

4.- La funcion "removeOdds" tiene un coste del orden de O(n), ya que consiste en entre 1 y 3 accesos a un array (constante)
dentro de un bucle for que va a iterar n veces.
*/

//2.-
int removeOdds(vector<int> &e, const int &n) {
	//k indica el numero de pares hasta el momento, que usare para almacenar tambien el 
	//indice donde meter el siguiente par que entre
	int k = 0;
	for (size_t i = 0; i < n; i++) {
		if (e[i] % 2 == 0) {
			e[k] = e[i];
			k++;
		}
	}
	return k;
}

bool solve() {
	vector<int> elementos;
	int n, aux;
	cin >> n;
	if (n == -1) return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		elementos.push_back(aux);
	}

	int k = removeOdds(elementos, elementos.size());

	if (k != 0) {
		for (int j = 0; j < k; j++) {
			cout << elementos[j] << " ";
		}
	} else {
		cout << endl;
	}
	cout << endl;
	return true;
}

int main() {
	while (solve()) {}
	return 0;
}
