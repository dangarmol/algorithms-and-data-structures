//Grupo TAIS14
//Juan Alberto Camino Saez
//Daniel Garcia Molero

#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>
#include "GrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

class PrimMST {
private:
    vector<Arista<int>> edgeTo;
    vector<int> distTo;
    vector<bool> marked;
	int costeTotal;
	int numAristas;
    
   void visit(GrafoValorado<int> g, size_t v, IndexPQ<int> &pq)
    {  // Add v to tree; update data structures.
        marked[v] = true;
        for (Arista<int> e : g.adj(v))
        {
            size_t w = e.otro(v);
            if (marked[w]) continue;
            if (e.valor() < distTo[w])
            {  // Edge e is new best connection from tree to w.
                edgeTo[w] = e;
                distTo[w] = e.valor();
				pq.update(w, distTo[w]);
            } 
		}
    }
    
public:
    PrimMST(GrafoValorado<int> g) {
		costeTotal = 0;
		numAristas = 0;
		IndexPQ<int> pq(g.V());
        edgeTo = vector<Arista<int>>(g.V());
        distTo = vector<int>(g.V());
        marked = vector<bool>(g.V());
        for (int v = 0; v < g.V(); v++)
            distTo[v] = 10000000;
        distTo[0] = 0;
        pq.push(0, 0);              // Initialize pq with 0, weight 0.
		while (!pq.empty()) {
			numAristas++;
			size_t p = pq.top().elem;
			pq.pop();
			costeTotal += distTo[p];
			visit(g, p, pq);       // Add closest vertex to tree.
		}
       
    }

	int getCosteTotal() {
		if (numAristas >= edgeTo.size()) {
			return costeTotal;
		}
		else {
			return -1;
		}
	}

};

int resuelveCaso(GrafoValorado<int> g) {
	PrimMST camino(g);
	return camino.getCosteTotal();
}

bool recubrimiento(vector<bool> vertices) {
	for (int i = 0; i < vertices.size(); ++i) {
		if (!vertices[i]) return false;
	}
	return true;
}

bool resuelve() {
    int nIslas, nPuentes, a, b, precio;
	
    cin >> nIslas;
    if (!cin) return false;
    cin >> nPuentes;
    GrafoValorado<int> g = GrafoValorado<int>(nIslas);
    for (int i = 0; i < nPuentes; ++i) {
        cin >> a >> b >> precio;
        Arista<int> puente = Arista<int>(a - 1, b - 1, precio);
        g.ponArista(puente);
    }
	if (nIslas == 1) {
		cout << 0 << '\n';
	}
	else {
		int coste = resuelveCaso(g);
		if (coste == -1) {
			cout << "No hay puentes suficientes" << '\n';
		}
		else {
			cout << coste << '\n';
		}
	}
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
    while (resuelve()) {}
    
    // para dejar todo como estaba al principio
/*#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/
    return 0;
}