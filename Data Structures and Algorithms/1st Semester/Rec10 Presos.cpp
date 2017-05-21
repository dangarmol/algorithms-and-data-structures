//
//  Rec10.cpp
//  Rec10
//
//  Created by Daniel García on 15/12/2016.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char buscarFugado(const size_t &start, const size_t &end, const vector<char> &listaPresos) {
    char solDer, solIzq;
    if (end - start > 1) {
        if (end - start != listaPresos[(start + end) / 2] - listaPresos[end])
            solIzq = buscarFugado((start + end) / 2, end, listaPresos);
        if (end - start != listaPresos[start] - listaPresos[(start + end) / 2])
            solDer = buscarFugado(start, (start + end) / 2, listaPresos);
        return max(solDer, solIzq);
    } else {
        if (listaPresos[end] - listaPresos[start] == 1) {
            return '0';
        } else {
            return listaPresos[start] + 1;
        }
    }
}

void solve(const char &start, const char &end) {
    string presos;
    vector<char> listaPresos;
    cin.ignore();
    getline(cin, presos);
    for (int i = 0; i < presos.length(); ++i) {
        if (presos[i] != ' ') {
            listaPresos.push_back(presos[i]);
        }
    }
    if (listaPresos[0] != start) {
        cout << start << endl;
    } else if (listaPresos[listaPresos.size() - 1] != end) {
        cout << end << endl;
    } else {
        cout << buscarFugado(0, listaPresos.size() - 1, listaPresos) << endl;
    }
}

int main() {
    int cases;
    char a, b;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
