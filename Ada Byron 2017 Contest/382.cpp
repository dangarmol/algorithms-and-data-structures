//
//  382.cpp
//  382
//
//  Created by Daniel García Molero on 28/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Antenna {
    int start;
    int end;
};

bool operator < (const Antenna & a, const Antenna & b){
    if(a.start < b.start) return true;
    else if (a.start == b.start) return a.end > b.end;
    else return false;
}

bool greedyAntennas(const vector<Antenna> &v, const size_t &length) {
    int covered = 0;
    if (v[0].start > 0) return false;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].start > covered) return false;
        if (v[i].end > covered) covered = v[i].end;
        if (covered >= length) return true;
    }
    return false;
}

void solve() {
    size_t length;
    vector<Antenna> v;
    Antenna aux;
    int pos, range;
    size_t nAntennas;
    cin >> length >> nAntennas;
    for (int i = 0; i < nAntennas; ++i) {
        cin >> pos >> range;
        aux.start = pos - range;
        aux.end = pos + range;
        v.push_back(aux);
    }
    sort(v.begin(), v.end(), less<Antenna>());
    if(greedyAntennas(v, length)) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    size_t nCases;
    cin >> nCases;
    while (nCases > 0) {
        solve();
        --nCases;
    }
    return 0;
}
