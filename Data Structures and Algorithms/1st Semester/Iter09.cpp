//EDA F02

//Invariante:
//(1 <= i <= n= && pivote = (menores(a,i,pivote) && (¬"Existe"j : 0 <= j < pivote : menores(a,i,j))) && (maxTotal = max k : 0 <= k <= i : v[k]) && (maxIz = max l : 0 <= l < pivote : v[l])

#include <iostream>
using namespace std;

int resolverCaso(int v[], int n) {
    int maxIz = v[0];
    int maxTotal = v[0];
    int pivote = 0;
    
    for (int i = 1; i < n; ++i) {
        if (v[i] >= maxTotal) {
            maxTotal = v[i];
        }
        if (v[i] <= maxIz) {
            pivote = i;
            maxIz = maxTotal;
        }
    }
    return pivote;
}

void resolver() {
    int n;
    int v[10000];
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    cout << resolverCaso(v, n) << endl;
}

int main() {
    int nCasos = 0;
    cin >> nCasos;
    
    for (int i = 0; i < nCasos; ++i)
        resolver();
    
    return 0;
}