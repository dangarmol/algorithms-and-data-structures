//
//  main.cpp
//  12b
//
//  Created by Daniel García Molero on 26/10/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include "Grafo.h"
#include <iostream>
#include <cmath>
using namespace std;

const int V = 10000;

class BreadthFirst {
public:
    BreadthFirst(const size_t &inicio, const size_t &fin) : marked(V, false) {
        bfs(inicio, fin);
    }
    
    int logDepth() {
        int sol = 0, cont = 1;
        while (cont < depth)
        {
            ++sol;
            cont = cont * 3;
        }
        return sol;
    }
    
private:
    int depth = 0;				  // profundidad explorada
    std::vector<bool> marked;     // el punto ha sido recorrido
    
    void bfs(const size_t &inicio, const size_t &fin) {
        std::queue<size_t> q;
        marked[inicio] = true;
        q.push(inicio);
        while (1) {
            auto v = q.front();
            q.pop();
            if (v == fin) break;
            if(!marked[(v + 1) % V]) {
                q.push((v + 1) % V);
                marked[(v + 1) % V] = true;
            }
            if(!marked[(v * 2) % V]) {
                q.push((v * 2) % V);
                marked[(v * 2) % V] = true;
            }
            if(!marked[v / 3]) {
                q.push(v / 3);
                marked[v / 3] = true;
            }
            ++depth;
        }
    }
    
};

bool resuelve() {
    int inicio, fin;
    cin >> inicio;
    if (!cin)
    {
        return false;
    }
    else
    {
        cin >> fin;
        BreadthFirst b = BreadthFirst(inicio, fin);
        cout << b.logDepth() << '\n';
    }
    return true;
}

int main() {
    while (resuelve());
    return 0;
}