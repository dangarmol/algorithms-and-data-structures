//Juan Alberto Camino Sáez
//Daniel García Molero
//Grupo 14

#include <iostream>

#include "Grafo.h"

using namespace std;

//El coste de esta función es de V * (V + E) en el caso peor (sin aristas), ya que realiza una búsqueda en profundidad en el grafo y lo realiza por cada vertice, 
//aunque seguramente el coste sea menor ya que solo se hace la búsqueda para los vértices no marcados
int mayorNumeroAmigos(const Grafo &grafo) {
	int maximo = 0;
	DepthFirstSearch dfs(grafo, 0);
	int cont = dfs.count();

	for (int i = 1; i < grafo.V(); ++i) {
		if (!dfs.marked(i)) {
			DepthFirstSearch dfs(grafo, i);
			int cont = dfs.count();
			if (maximo < cont) {
				maximo = cont;
			}
		}
	}
	if (maximo < cont) {
		maximo = cont;
	}
	return maximo;

}

void resuelve() {
	int vertices, aristas;

	cin >> vertices;
	cin >> aristas;

	Grafo grafo(vertices);
	for (int i = 0; i < aristas; ++i) {
		int a1, a2;
		cin >> a1;
		cin >> a2;
		grafo.ponArista(a1 - 1, a2 - 1);
	}

	cout << mayorNumeroAmigos(grafo) << '\n';


}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		resuelve();
	}
	return 0;
}