//
//  Rec06.cpp
//  Rec06
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void polidivisibles (const long long &number, const int &maxDigits, const int &currentDigit) {
    long long next;
    if (maxDigits >= currentDigit) {
        for (int i = 0; i < 10; ++i) {
            next = 10 * number + i;
            if(next % currentDigit == 0) {
                cout << next << endl;
                polidivisibles(next, maxDigits, currentDigit + 1);
            }
        }
    }
}

bool solve() {
    long long n, d, nextDigit = 2, aux = 10;
    cin >> n >> d;
    if(!cin) return false;
    while(aux <= n) {
        nextDigit++;
        aux *= 10;
    }
    cout << n << endl;
    polidivisibles(n, d, nextDigit);
    cout << "---" << endl;
    return true;
}

int main() {
    while (solve()) {}
	system("pause");
    return 0;
}
