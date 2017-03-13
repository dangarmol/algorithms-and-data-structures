//
//  319.cpp
//  319
//
//  Created by Daniel García Molero on 10/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

using Adys = std::vector<size_t>;  // lista de adyacentes a un vértice
using Path = std::deque<size_t>;   // para representar caminos

class GrafoDirigido {
public:
    
    /**
     * Crea un grafo dirigido con V vértices, de 0 a V-1.
     */
    GrafoDirigido(size_t v) : _V{v}, _E{0}, _adj(_V) {}
    
    /**
     * Devuelve el número de vértices del grafo.
     */
    size_t V() const { return _V; }
    
    /**
     * Devuelve el número de aristas del grafo.
     */
    size_t E() const { return _E; }
    
    /**
     * Añade la arista dirigida v-w al grafo.
     * @throws invalid_argument si algún vértice no existe
     */
    void ponArista(size_t v, size_t w) {
        if (v >= _V || w >= _V) throw std::invalid_argument("Vértice inexistente");
        ++_E;
        _adj[v].push_back(w);
    }
    
    /**
     * Comprueba si hay arista de u a v.
     */
    bool hayArista(size_t v, size_t w) const {
        if (v >= _V || w >= _V) throw std::invalid_argument("Vértice inexistente");
        for (auto u : _adj[v])
            if (u == w) return true;
        return false;
    }
    
    /**
     * Devuelve la lista de adyacencia de v.
     * @throws invalid_argument si v no existe
     */
    Adys const& adj(size_t v) const {
        if (v >= _V) throw std::invalid_argument("Vértice inexistente");
        return _adj[v];
    }
    
    /**
     * Devuelve el grafo dirigido inverso.
     */
    GrafoDirigido reverse() const {
        GrafoDirigido R(_V);
        for (auto v = 0; v < _V; ++v) {
            for (auto w : _adj[v]) {
                R.ponArista(w, v);
            }
        }
        return R;
    }
    
    /**
     * Muestra el grafo en el stream de salida o
     */
    void print(std::ostream& o = std::cout) const {
        o << _V << " vértices, " << _E << " aristas\n";
        for (auto v = 0; v < _V; ++v) {
            o << v << ": ";
            for(auto w : _adj[v]) {
                o << w << " ";
            }
            o << "\n";
        }
    }
    
private:
    size_t _V;   // número de vértices
    size_t _E;   // número de aristas
    std::vector<Adys> _adj;   // vector de listas de adyacentes
};

/**
 * Para mostrar grafos por la salida estándar.
 */
inline std::ostream& operator<<(std::ostream& o,GrafoDirigido const& g) {
    g.print(o);
    return o;
}

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
