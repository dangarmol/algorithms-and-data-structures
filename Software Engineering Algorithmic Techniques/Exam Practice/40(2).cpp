#include <iostream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

struct Cancion {
    int duracion;
    int puntuacion;
};

bool operator>(Cancion const& a, Cancion const& b) {
    return (a.puntuacion*1.0 / a.duracion*1.0) > (b.puntuacion*1.0 / b.duracion*1.0);
}

struct Nodo {
    vector<int> sol;
    int k;
    int duracion1, duracion2; //duracion acumulada cinta 1 y 2
    int puntuacion1, puntuacion2; //puntuacion acumulada cinta 1 y 2
    int puntuacion_est; //prioridad
};

bool operator>(Nodo const& a, Nodo const& b) {
    return a.puntuacion_est > b.puntuacion_est;
}


int calculoVoraz(vector<Cancion> const& canciones, int dMax, int k, int duracion1, int puntuacion1, int duracion2, int puntuacion2) {
    int hueco = 2*dMax - duracion1 - duracion2;
    float estimacion = puntuacion1 + puntuacion2;
    int j = k + 1;
    
    //solo canciones enteros
    while (j < canciones.size() && canciones[j].duracion <= hueco) {
        hueco -= canciones[j].duracion;
        estimacion += canciones[j].puntuacion;
        j++;
    }
    if (j < canciones.size()) {
        estimacion += (hueco*1.0 / canciones[j].duracion*1.0)* canciones[j].puntuacion;
    }
    return estimacion;
}


void cancion_rp(vector<Cancion> const& canciones, int dMax, vector<int> & sol_mejor, int & punt_mejor) {
    int N = canciones.size();
    //int dMax1 = dMax, dMax2 = dMax;
    Nodo Y;
    Y.sol = vector<int>(N);
    Y.k = -1;
    Y.duracion1 = Y.puntuacion1 = Y.duracion2 = Y.puntuacion2 = 0;
    Y.puntuacion_est = calculoVoraz(canciones, dMax, Y.k, Y.duracion1, Y.puntuacion1, Y.duracion2, Y.puntuacion2);
    PriorityQueue<Nodo, greater<Nodo>> cola;
    cola.push(Y);
    punt_mejor = -1;
    
    while (!cola.empty() && cola.top().puntuacion_est > punt_mejor) {
        Y = cola.top(); cola.pop();
        Nodo X(Y);
        X.k++;
        //probar meter en primera cinta
        if (Y.duracion1 + canciones[X.k].duracion <= dMax) {
            X.sol[X.k] = 1;
            X.duracion2 = Y.duracion2;
            X.puntuacion2 = Y.puntuacion2;
            X.duracion1 = Y.duracion1 + canciones[X.k].duracion;
            X.puntuacion1 = Y.puntuacion1 + canciones[X.k].puntuacion;
            X.puntuacion_est = Y.puntuacion_est;
            if (X.k == N - 1) {
                sol_mejor = X.sol;
                punt_mejor = X.puntuacion1 + X.puntuacion2;
            }
            else {
                cola.push(X);
            }
        }
        //probar meter en segunda cinta
        if (Y.duracion2 + canciones[X.k].duracion <= dMax) {
            X.sol[X.k] = 2;
            X.duracion1 = Y.duracion1;
            X.puntuacion1 = Y.puntuacion1;
            X.duracion2 = Y.duracion2 + canciones[X.k].duracion;
            X.puntuacion2 = Y.puntuacion2 + canciones[X.k].puntuacion;
            X.puntuacion_est = Y.puntuacion_est;
            if (X.k == N - 1) {
                sol_mejor = X.sol;
                punt_mejor = X.puntuacion2 + X.puntuacion1;
            }
            else {
                cola.push(X);
            }
        }
        //punt_mejor = X.puntuacion2 + X.puntuacion1;
        //probar no meter objeto
        X.puntuacion_est = calculoVoraz(canciones, dMax, X.k, Y.duracion1, Y.puntuacion1, Y.duracion2, Y.puntuacion2);
        if (X.puntuacion_est > punt_mejor) {
            X.duracion1 = Y.duracion1;
            X.duracion2 = Y.duracion2;
            X.puntuacion1 = Y.puntuacion1;
            X.puntuacion2 = Y.puntuacion2;
            X.sol[X.k] = 0;
            if (X.k == N - 1) {
                sol_mejor = X.sol;
                punt_mejor = X.puntuacion1 + X.puntuacion2;
            }
            else {
                cola.push(X);
            }
        }
    }
    
}

void resuelveCaso(int nCanciones, int dMax) {
    vector<Cancion> canciones(nCanciones);
    int dur, punt;
    for (int i = 0; i < nCanciones; i++) {
        cin >> dur;
        cin >> punt;
        canciones[i].duracion = dur;
        canciones[i].puntuacion = punt;
    }
    sort(canciones.begin(), canciones.end(), greater<Cancion>());
    
    vector<int> sol_mejor(nCanciones, 0);
    int punt_mejor = 0;
    
    cancion_rp(canciones, dMax, sol_mejor, punt_mejor);
    
    cout << punt_mejor << endl;
}
