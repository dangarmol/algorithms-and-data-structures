//Juan Alberto Camino S·ez
//Daniel GarcÌa Molero
//Grupo 14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cofre {
public:
    int profundidad;
    int valor;
    
    Cofre() {}
    Cofre(int p, int v) {
        profundidad = p;
        valor = v;
    }
};

int maxValor(const vector<Cofre> &cofres, int i, int j) {
    if (i == cofres.size()) return 0;
    if (3 * cofres[i].profundidad > j) return maxValor(cofres, i + 1, j);
    else return max(maxValor(cofres, i + 1, j), cofres[i].valor + maxValor(cofres, i + 1, j - 3 * cofres[i].profundidad));
}

//La recurrencia usada en este ejercicio es
//maxOro(i, j) = {
//	maxOro (i - 1, j) si profundidad[i] * 3 >= j
//	max(maxOro(i - 1, j), maxOro(i, j - 3 * p[i]) si profundidad[i] * 3 < j
// }
// El coste en tiempo y en espacio es de O(n^2), aunque en espacio podrÌa ser lineal
void maxValor(const vector<Cofre> &cofres, vector<vector<int>> &matriz, int tiempo) {
    int n = cofres.size() - 1;
    matriz = vector<vector<int>>(n + 1, vector<int>(tiempo + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= tiempo; ++j) {
            if (3 * cofres[i].profundidad > j) matriz[i][j] = matriz[i - 1][j];
            else matriz[i][j] = max(matriz[i - 1][j], cofres[i].valor + matriz[i - 1][j - 3 * cofres[i].profundidad]);
        }
    }
}

vector<bool> obtenerSolucion(const vector<Cofre> &cofres, vector<vector<int>> &matriz, int tiempo, int &contador) {
    vector<bool> coger(cofres.size(), false);
    
    int j = tiempo;
    contador = 0;
    for (int i = cofres.size() - 1; i >= 1; --i) {
        if (matriz[i][j] != matriz[i - 1][j]) {
            coger[i] = true;
            j = j - 3 * cofres[i].profundidad;
            contador++;
        }
    }
    return coger;
}

void mostrar(const vector<Cofre> &cofres, const vector<bool> &coger, int maxValor, int contador) {
    cout << maxValor << '\n';
    cout << contador << '\n';
    for (int i = 1; i < cofres.size(); ++i) {
        if (coger[i]) cout << cofres[i].profundidad << " " << cofres[i].valor << '\n';
    }
    cout << "----" << '\n';
}

bool resuelve() {
    int tiempo;
    
    cin >> tiempo;
    if (!cin) return false;
    else {
        int nCofres, contador;
        
        cin >> nCofres;
        vector<Cofre> cofres(nCofres + 1);
        vector<vector<int>> matriz;
        vector<bool> coger;
        
        for (int i = 1; i < cofres.size(); ++i) {
            cin >> cofres[i].profundidad >> cofres[i].valor;
        }
        maxValor(cofres, matriz, tiempo);
        coger = obtenerSolucion(cofres, matriz, tiempo, contador);
        mostrar(cofres, coger, matriz[nCofres][tiempo], contador);
        //cout << maximo << endl;
        return true;
    }
}

int main() {
    while (resuelve()) {}
    return 0;
}
