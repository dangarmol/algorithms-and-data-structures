//
//  main.cpp
//  EvaluacionEDA2
//
//  Created by Daniel García Molero on 27/10/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

int N = 10000;

bool resuelveCaso(const int v[], const int &n, const int &p) {
    if(p == n - 1) {
        return true;
    }
    int maxLeft = v[0], minRight = v[p + 1];
    for (int i = 0; i <= p; ++i) {
        if(v[i] >= maxLeft) maxLeft = v[i];
    }
    for (int j = p + 1; j < n; ++j) {
        if(v[j] <= minRight) minRight = v[j];
    }
    if (maxLeft < minRight) {
        return true;
    }
    return false;
}

int main() {
    int v[N];
    int numCasos, n, p;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        cin >> n >> p;
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        if(resuelveCaso(v, n, p)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
