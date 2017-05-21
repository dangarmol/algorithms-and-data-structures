//
//  main.cpp
//  08
//
//  Created by Daniel García Molero on 13/10/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void calcularMedianas(const vector <int> &v) {
    
}

int main() {
    vector <int> vector;
    int nCasos, aux;
    
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        cin >> aux;
        vector.push_back(aux);
    }
    calcularMedianas(vector);
    return 0;
}