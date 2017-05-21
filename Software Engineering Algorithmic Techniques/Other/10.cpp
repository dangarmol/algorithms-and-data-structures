//
//  10.cpp
//  10
//
//  Created by Daniel García Molero on 21/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
#include "Grafo.h"
using namespace std;

class BreadthFirstColors {
public:
    BreadthFirstColors(Grafo const& G, size_t s)
    : marked(G.V(), false), edgeTo(G.V()), distTo(G.V()), s(s) {
        if (s >= G.V()) throw std::invalid_argument("Vértice inexistente");
        bfs(G, s);
        for (int i = 0; i < marked.size(); ++i) {
            if (!marked[i]) {
                bfs(G, i);
            }
        }
    }
    
    // Hay camino del origen a v?
    bool hasPathTo(size_t v) const {
        return marked.at(v);
    }
    
    // Devuelve el camino más corto desde el origen a v (vacío si no están conectados).
    Path pathTo(size_t v) const {
        Path path;
        if (!hasPathTo(v)) return path;
        for (auto x = v; x != s; x = edgeTo[x])
            path.push_front(x);
        path.push_front(s);
        return path;
    }
    
    // Devuelve el número de aristas en el camino más corto a v
    size_t distance(size_t v) const {
        return distTo.at(v);
    }
    
    bool esBip() const {
        return bip;
    }
    
private:
    std::vector<bool> marked;     // marked[v] = hay camino s-v?
    std::vector<size_t> edgeTo;   // edgeTo[v] = último vértice antes de llegar a v
    std::vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto
    size_t s;                     // vértice origen
    bool bip = true;
    
    void bfs(Grafo const& G, size_t s) {
        std::queue<size_t> q;
        distTo[s] = 0;
        marked[s] = true;
        q.push(s);
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (auto w : G.adj(v)) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                    marked[w] = true;
                    q.push(w);
                }
                if (distTo[v] % 2 == distTo[w] % 2) {
                    bip = false;
                    return;
                }
            }
        }
    }
};

string bipartito(const Grafo &graph) {
    BreadthFirstColors bfc = BreadthFirstColors(graph, 0);
    if (!bfc.esBip()) {
        return "NO";
    }
    return "SI";
}

bool resuelve() {
    size_t v, a, from, to;
    cin >> v;
    if (!cin) return false;
    Grafo graph = Grafo(v);
    cin >> a;
    for (int i = 0; i < a; ++i) {
        cin >> from >> to;
        graph.ponArista(from, to);
    }
    
    cout << bipartito(graph) << endl;
    return true;
}

int main() {
    while (resuelve()) {}
    return 0;
}
