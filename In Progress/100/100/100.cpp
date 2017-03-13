//
//  100.cpp
//  100
//
//  Created by Daniel García Molero on 27/02/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int KAP = 6174;

class numberWithOps {
private:
    short int a;
    short int b;
    short int c;
    short int d;
public:
    numberWithOps(short int a, short int b, short int c, short int d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    
    bool makeNext() {
        int carry;
        if(this->a * 1000 + this->b * 100 + this->c * 10 + this->d == KAP) return false;
        else {
            vector<short int> v;
            v.push_back(this->a);
            v.push_back(this->b);
            v.push_back(this->c);
            v.push_back(this->d);
            sort(v.begin(), v.end(), greater<short int>());
            this->d = 10 + v[3] - v[0];
            if(this->d > 9) {
                this->d -= 10;
                carry = 0;
            } else {
                carry = 1;
            }
            this->c = 10 + v[2] - v[1] - carry;
            if(this->c > 9) {
                this->c -= 10;
                carry = 0;
            } else {
                carry = 1;
            }
            this->b = 10 + v[1] - v[2] - carry;
            if(this->b > 9) {
                this->b -= 10;
                carry = 0;
            } else {
                carry = 1;
            }
            this->a = 10 + v[0] - v[3] - carry;
            if(this->a > 9) {
                this->a -= 10;
                carry = 0;
            } else {
                carry = 1;
            }
        }
        return true;
    }
};

size_t getIterations(size_t iterations, numberWithOps n) {
    if(!n.makeNext()) return iterations;
    else return getIterations(iterations + 1, n);
}

void solve(string &number) {
    size_t iterations = 0;
    int num = atoi(number.c_str());
    if(num % 1111 == 0) iterations = 8;
    while (num != KAP) {
        sort(number.begin(), number.end());
        number = to_string(42);
    }
    cout << iterations << endl;
}

int main() {
    size_t nCases;
    string number;
    cin >> nCases;
    for (size_t i = 0; i < nCases; ++i) {
        cin >> number;
        solve(number);
    }
    return 0;
}
