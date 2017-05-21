//
//  main.cpp
//  12
//
//  Created by Daniel García Molero on 29/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include "GrafoDirigido.h"
using namespace std;

/**
 * Recorrido en anchura de un grafo a partir de un vértice origen.
 * Permite recuperar los caminos más cortos desde el origen a todos los vértices alcanzables.
 */
class BreadthFirstBestPath {
public:
    // BFS desde un único origen
    BreadthFirstBestPath(GrafoDirigido const& G, size_t s, size_t end) : marked(G.V(), false),
    edgeTo(G.V()), distTo(G.V()), end(end) {
        bfs(G, { s } );
    }
    
    // Hay camino del origen a v?
    bool hasPathTo(size_t v) const { return marked.at(v); }
    
    // Devuelve el camino más corto desde el origen a v (vacío si no están conectados).
    Path pathTo(size_t v) const {
        Path path;
        if (!hasPathTo(v)) return path;
        size_t x;
        for (x = v; distTo[x] != 0; x = edgeTo[x])
            path.push_front(x);
        path.push_front(x);
        return path;
    }
    
    // Devuelve el número de aristas en el camino más corto a v
    size_t distance(size_t v) const {
        return distTo.at(v);
    }
    
private:
    std::vector<bool> marked;     // marked[v] = hay camino s-v?
    std::vector<size_t> edgeTo;   // edgeTo[v] = último vértice antes de llegar a v
    std::vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto
    size_t end;
    
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
                    if (w == end) {
                        out = true;
                        break;
                    }
                    q.push(w);
                }
            }
        }
    }
};

bool getPresses(const GrafoDirigido &g) {
    int start, end;
    cin >> start >> end;
    if(!cin) return false;
    cout << BreadthFirstBestPath(g, start, end).distance(end) << endl;
    return true;
}

GrafoDirigido createGraph() {
    GrafoDirigido g = GrafoDirigido(10000);
    for (int i = 0; i < g.V(); ++i) {
        g.ponArista(i, (i + 1) % 10000);
        g.ponArista(i, (i * 2) % 10000);
        g.ponArista(i, i / 3);
    }
    return g;
}

int main() {
    GrafoDirigido g = createGraph();
    while (getPresses(g)) {}
    return 0;
}
