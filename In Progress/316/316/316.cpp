//
//  316.cpp
//  316
//
//  Created by Daniel García Molero on 15/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tDay {
    int accWon;
    size_t index;
};

bool operator< (tDay a, tDay b){
    return a.accWon < b.accWon;
}

void getBestDays(const vector<tDay> &days) {
    size_t start = 0, end = days.size();
    bool found = false;
    while (!found) {
        if (days[start].index < days[end].index) {
            found = true;
        } else {
            if (days[start + 1].accWon - days[start].accWon > days[end - 1].accWon - days[end].accWon) {
                end--;
            } else {
                start++;
            }
        }
    }
    cout << "SOL: " << days[start].index << " " << days[end].index << endl;
}

void solve() {
    size_t nDays;
    cin >> nDays;
    vector<tDay> days(nDays + 1);
    days[0].accWon = 0;
    days[0].index = 0;
    for (size_t i = 1; i <= nDays; ++i) {
        cin >> days[i].accWon;
        days[i].index = i;
        days[i].accWon += days[i - 1].accWon;
    }
    sort(days.begin(), days.end());
    getBestDays(days);
}

int main() {
    size_t nCases;
    cin >> nCases;
    for (size_t i = 0; i < nCases; ++i) {
        solve();
    }
    return 0;
}
