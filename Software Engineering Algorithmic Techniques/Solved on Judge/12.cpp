//Grupo TAIS14
//Juan Alberto Camino Saez
//Daniel García Molero

#include "GrafoDirigido.h"
#include <iostream>
using namespace std;

const int V = 10000;

/**
 * Recorrido en anchura de un grafo a partir de un vértice origen.
 * Permite recuperar los caminos más cortos desde el origen a todos los vértices alcanzables.
 */
class BreadthFirstShortestPath {
public:
    // BFS desde un único origen
    BreadthFirstShortestPath(GrafoDirigido const& G, size_t s, size_t end) : marked(G.V(), false),
    edgeTo(G.V()), distTo(G.V()), last(end) {
        bfs(G, { s } );
    }
    
    // Devuelve el número de aristas en el camino más corto a v
    size_t distance(size_t v) const {
        return distTo.at(v);
    }
    
private:
    std::vector<bool> marked;     // marked[v] = hay camino s-v?
    std::vector<size_t> edgeTo;   // edgeTo[v] = último vértice antes de llegar a v
    std::vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto
    size_t last;
    
    //Esta función tiene coste del orden de E + V
    void bfs(GrafoDirigido const& G, std::vector<size_t> const& ss) {
        bool out = false;
        std::queue<size_t> q;
        for(auto s : ss) {
            if (s >= G.V()) throw std::invalid_argument("Vértice inexistente");
            distTo[s] = 0;
            marked[s] = true;
            q.push(s);
        }
        while (!q.empty() && !out) {
            size_t v = q.front(); q.pop();
            for (size_t w : G.adj(v)) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                    marked[w] = true;
                    q.push(w);
                    if (w == last) {
                        out = true;
                        break;
                    }
                }
            }
        }
    }
};

size_t casoPrueba(const GrafoDirigido &grafo, const int &m, const int &n) {
    return BreadthFirstShortestPath(grafo, m, n).distance(n);
}

//Esta funcion tiene coste lineal V.
void crearAristas(GrafoDirigido &grafo) {
    for (int i = 0; i < V; ++i) {
            grafo.ponArista(i, (i + 1) % V);
            grafo.ponArista(i, (i * 2) % V);
            grafo.ponArista(i, i / 3);
    }
}

int main() {
    int m, n;
    GrafoDirigido grafo = GrafoDirigido(V);
    crearAristas(grafo);
    while (cin >> m >> n) {
        cout << casoPrueba(grafo, m, n) << '\n';
    }
    return 0;
}