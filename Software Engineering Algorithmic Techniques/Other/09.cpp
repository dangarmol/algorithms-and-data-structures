//
//  09.cpp
//  09
//
//  Created by Daniel García Molero on 21/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
#include "Grafo.h"
using namespace std;

string esLibre(const DepthFirstPaths &dfs, const size_t &size) {
    if (dfs.getCyclic()) {
        return "NO";
    }
    for (int i = 0; i < size; ++i) {
        if (!dfs.hasPathTo(i)) {
            return "NO";
        }
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
    
    cout << esLibre(DepthFirstPaths(graph, 0), graph.V()) << endl;
    return true;
}

int main() {
    while (resuelve()) {}
    return 0;
}
