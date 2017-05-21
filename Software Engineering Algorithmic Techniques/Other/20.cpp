//
//  20.cpp
//  20
//
//  Created by Daniel García Molero on 28/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

int discount(PriorityQueue<size_t, greater<size_t>> &books) {
    int bestDeal = 0, counter = 0;
    if (books.size() < 3) {
        return 0;
    }
    while (!books.empty()) {
        ++counter;
        if (counter % 3 == 0) {
            bestDeal += books.top();
        }
        books.pop();
    }
    return bestDeal;
}

bool resuelve() {
    size_t nCases, price;
    PriorityQueue<size_t, greater<size_t>> books = PriorityQueue<size_t, greater<size_t>>();
    if (!cin) return false;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> price;
        books.push(price);
    }
    cout << discount(books) << endl;
    return true;
}

int main() {
    while (resuelve()) {}
    return 0;
}
