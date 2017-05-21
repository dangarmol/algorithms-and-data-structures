//
//  mergesortRecursivo.cpp
//  MergesortRecursivo
//
//  Created by Daniel García Molero on 23/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

void mezclar(int v[], const int &a, const int &m, const int &b) {
    int w[b - a + 1];
    int i, j, k;
    for (k = a; k <= b; ++k) {
        w[k - a] = v[k];
    }
    i = 0;
    j = m - a + 1;
    k = a;
    while ((i <= m - a) && (j <= b - a)) {
        if (w[i] <= w[j]) {
            v[k] = w[i];
            i = i + 1;
        } else {
            v[k] = w[j]; j = j + 1;
        }
        k = k + 1;
    }
    while (i <= m - a) {
        v[k] = w[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= b - a) {
        v[k] = w[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergesort(int v[], const int &a, const int &b) {
    if(a < b) {
        int m = (a + b) / 2;
        mergesort(v, a, m);
        mergesort(v, m + 1, b);
        mezclar(v, a, m, b);
    }
}

void mergesort (int v[], const int &n) {
    mergesort(v, 0, n - 1);
}

int main() {
    const int n = 8;
    int v[n] = {5, 2, 4, 1, 7, 8, 3, 0};
    mergesort(v, n);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
