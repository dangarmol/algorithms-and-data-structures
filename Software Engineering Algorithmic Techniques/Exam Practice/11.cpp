//
//  11.cpp
//  11
//
//  Created by Daniel García Molero on 29/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include "Grafo.h"
using namespace std;

int biggestGroup(const Grafo &graph) {
    DepthFirstSearch dfs = DepthFirstSearch(graph, 0);
    int mostFriends = dfs.count();
    for (int i = 1; i < graph.V(); ++i) {
        if (!dfs.marked(i)) {
            dfs = DepthFirstSearch(graph, i);
            if (dfs.count() > mostFriends) {
                mostFriends = dfs.count();
            }
        }
    }
    return mostFriends;
}

int createAndSolve(const int &nPeople, const int &nPairs) {
    int a, b;
    Grafo graph = Grafo(nPeople);
    for (int i = 0; i < nPairs; ++i) {
        cin >> a >> b;
        graph.ponArista(a - 1, b - 1);
    }
    return biggestGroup(graph);
}

int main() {
    int nCases, nPeople, nPairs;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> nPeople >> nPairs;
        cout << createAndSolve(nPeople, nPairs) << endl;
    }
    return 0;
}
