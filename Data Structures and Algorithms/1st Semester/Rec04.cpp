//
//  Rec04.cpp
//  Rec04
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long long int fibonacci (const int &n, vector<long long int> &v) {
    switch (n) {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    default:
        if(v[n] == -1) {
            v[n] = fibonacci(n - 1, v) + fibonacci(n - 2, v);
        }
        return v[n];
        break;
    }
}

bool solve (vector <long long int> &v) {
    int number;
    cin >> number;
    if (!cin) return false;
    cout << fibonacci(number, v) << endl;
    return true;
}

int main() {
    vector<long long int> v(10000, -1);
    while (solve(v)) {}
    return 0;
}
