//Juan Alberto Camino Saez
//Daniel Garcia
//Grupo 14

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getDiscount(const vector<int> &books) {
    int discount = 0;
    for (int i = 2; i < books.size(); i+=3) {
        discount += books[i];
    }
    return discount;
}

bool solve() {
    vector<int> books;
    int nBooks, aux;
    cin >> nBooks;
    if(!cin) return false;
    for (int i = 0; i < nBooks; ++i) {
        cin >> aux;
        books.push_back(aux);
    }
    sort(books.begin(), books.end(), greater<int>());
    cout << getDiscount(books) << endl;
    return true;
}

int main() {
    while(solve()){}
    return 0;
}
