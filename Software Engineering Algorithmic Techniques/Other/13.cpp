//
//  13.cpp
//  13
//
//  Created by Daniel García Molero on 17/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include "GrafoDirigido.h"
#include "TreeMap_AVL.h"
using namespace std;

class BreadthFirstBestPath {
public:
    // BFS desde un único origen
    BreadthFirstBestPath(GrafoDirigido const& G, size_t s, size_t end) : marked(G.V(), false),
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

class Arista {
private:
    size_t orig;
    size_t dest;
public:
    Arista() {}
    Arista(int oTile, int dTile) {
        orig = oTile;
        dest = dTile;
    }
    size_t getOrig() const {
        return orig;
    }
    size_t getDest() const {
        return dest;
    }
    void setOrig(size_t orig) {
        this->orig = orig;
    }
    bool operator< (const Arista &arista) const {
        if (orig < arista.getOrig()) {
            return true;
        }
        return false;
    }
};

void createPossibleMoves(GrafoDirigido &board, TreeMap<size_t, Arista> snakesAndLadders, const int &maxDice){
    Arista edgeToPlace;
    for (int current = 0; current < board.V() - 1; ++current) {
        for (int dice = 1; dice <= maxDice; ++dice) {
            if (snakesAndLadders.contains(current + dice)) {
                edgeToPlace = snakesAndLadders.at(current + dice);
                board.ponArista(current, edgeToPlace.getDest());
            } else {
                if ((current + dice) >= board.V()) continue;
                board.ponArista(current, current + dice);
            }
        }
    }
}

void resolverCaso(const int &n, const int &k, const int &s, const int &e) {
    GrafoDirigido board = GrafoDirigido(n * n);
    int oTile, dTile;
    TreeMap<size_t, Arista> snakesAndLadders = TreeMap<size_t, Arista>();
    Arista arista;
    for (int i = 0; i < s + e; ++i) {
        cin >> oTile;
        cin >> dTile;
        arista = Arista(oTile - 1, dTile - 1);
        snakesAndLadders.insert(arista.getOrig(), arista);
    }
    createPossibleMoves(board, snakesAndLadders, k);
    cout << BreadthFirstBestPath(board, 0, board.V()).distance(board.V() - 1) << endl;
}

bool resolver() {
    int n, k, s, e;
    cin >> n >> k >> s >> e;
    if (n == 0 && k == 0 && s == 0 && e == 0) return false;
    resolverCaso(n, k, s, e);
    return true;
}

int main() {
    while (resolver()) {}
    return 0;
}