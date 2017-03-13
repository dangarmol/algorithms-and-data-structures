//
//  381.cpp
//  381
//
//  Created by Daniel García Molero on 13/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool solve() {
    int nPlanets, aux, max = 0, mcm;
    bool found = false;
    cin >> nPlanets;
    if (nPlanets == 0) return false;
    vector<int> planets;
    for (int i = 0; i < nPlanets; ++i) {
        cin >> aux;
        planets.push_back(aux);
        if (max < aux) max = aux;
    }
    mcm = max;
    while (!found) {
        for (int j = 0; j < planets.size(); ++j) {
            if(mcm % planets[j] != 0) {
                mcm += max;
                break;
            }
            if (j == planets.size() - 1 && mcm % planets[j] == 0) found = true;
        }
    }
    cout << mcm << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
