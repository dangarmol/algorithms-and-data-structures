//
//  VA05.cpp
//  VA05
//
//  Created by Daniel García Molero on 06/02/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdexcept>
using namespace std;

const size_t TAM_INICIAL = 100;

// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class PriorityQueue {
public:
    
    PriorityQueue(size_t t = TAM_INICIAL, Comparator c = Comparator());
    
    /** Constructor a partir de un vector de elementos */
    PriorityQueue(std::vector<T> const& v_ini, Comparator c = Comparator());
    
    PriorityQueue(PriorityQueue<T, Comparator> const&) = default;
    
    //	PriorityQueue(PriorityQueue<T, Comparator> &&) = default;
    
    PriorityQueue<T, Comparator> & operator=(PriorityQueue<T, Comparator> const&) = default;
    
    //	PriorityQueue<T, Comparator> & operator=(PriorityQueue<T, Comparator> &&) = default;
    
    ~PriorityQueue() = default;
    
    
    /** Insertar el elemento x (que incluye su prioridad).
     Si no hay espacio, el array se agranda. */
    void push(T const& x);
    void push(T && x);
    
    /** Devuelve el número de elementos en la cola. */
    size_t size() const { return numElems; }
    
    bool empty() const { return (numElems == 0); }
    
    /* Si la cola no es vacía, devuelve el elemento más prioritario. */
    T const& top() const;
    
    /* Si la cola no es vacía, elimina el elemento más prioritario. */
    void pop();
    
    /* Si la cola no es vacía, elimina y devuelve el elemento más prioritario. */
    void pop(T & prim);
    
    /* Muestra el montículo por la salida o */
    void print(std::ostream& o = std::cout) const;
    
    
private:
    
    /** Vector que contiene los datos */
    std::vector<T> array;     // primer elemento en la posición 1
    
    /** Número de elementos en el montículo */
    size_t numElems;
    
    /** Objeto función que sabe comparar elementos.
     * antes(a,b) es cierto si a es más prioritario que b (a debe salir antes que b)
     */
    Comparator antes;
    
    /* Flota el elemento situado en la posición n del montículo. */
    void flotar(size_t n);
    
    /* Hunde el elemento situado en la posición n del montículo. */
    void hundir(size_t n);
    
    /* convierte un array en un montículo */
    void monticulizar();
};

template <typename T, typename Comparator>
inline std::ostream& operator<<(std::ostream & o, PriorityQueue<T, Comparator> const& a){
    a.print(o);
    return o;
}

/** Función para construir una cola con prioridad cuyo Comparator es una lambda. */
template<typename T, typename Comparator> // el tipo Comparator se deduce a partir de c
inline PriorityQueue<T, Comparator> make_priorityqueue(Comparator c, size_t tam = TAM_INICIAL)
{
    return PriorityQueue<T, Comparator>(tam, c);
}


template <typename T, typename Comparator>
PriorityQueue<T, Comparator>::PriorityQueue(size_t t, Comparator c) :
array(t + 1), numElems(0), antes(c) {};

template <typename T, typename Comparator>
PriorityQueue<T, Comparator>::PriorityQueue(std::vector<T> const& v_ini, Comparator c) :
array(2 * v_ini.size()), numElems(v_ini.size()), antes(c) {
    for (auto i = 0; i < v_ini.size(); ++i)
        array[i + 1] = v_ini[i];
    monticulizar();
};


template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::push(T const& x) {
    if (numElems == array.size() - 1)  // si el array se ha llenado se aumenta el tamaño
        array.resize(array.size() * 2);
    ++numElems;
    array[numElems] = x;
    flotar(numElems);
}
template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::push(T && x) {
    if (numElems == array.size() - 1)  // si el array se ha llenado se aumenta el tamaño
        array.resize(array.size() * 2);
    ++numElems;
    array[numElems] = std::move(x);
    flotar(numElems);
}

template <typename T, typename Comparator>
T const& PriorityQueue<T, Comparator>::top() const {
    if (empty()) throw std::domain_error("No se puede consultar el primero de una cola vacía.");
    else return array[1];
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::pop() {
    if (empty()) throw std::domain_error("Imposible eliminar el primero de una cola vacía");
    else {
        array[1] = std::move(array[numElems]);
        --numElems;
        hundir(1);
    }
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::pop(T & prim) {
    if (empty()) throw std::domain_error("Imposible eliminar el primero de una cola vacía");
    else {
        prim = std::move(array[1]);
        array[1] = std::move(array[numElems]);
        --numElems;
        hundir(1);
    }
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::print(std::ostream & o) const {
    for (auto i = 1; i <= numElems; ++i)
        o << array[i] << " ";
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::flotar(size_t n) {
    T elem = std::move(array[n]);
    size_t hueco = n;
    while (hueco != 1 && antes(elem, array[hueco / 2])) {
        array[hueco] = std::move(array[hueco / 2]);
        hueco /= 2;
    }
    array[hueco] = std::move(elem);
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::hundir(size_t n) {
    T elem = std::move(array[n]);
    size_t hueco = n;
    size_t hijo = 2 * hueco; // hijo izquierdo, si existe
    while (hijo <= numElems)  {
        // cambiar al hijo derecho si existe y va antes que el izquierdo
        if (hijo < numElems && antes(array[hijo + 1], array[hijo]))
            ++hijo;
        // flotar el hijo si va antes que el elemento hundiéndose
        if (antes(array[hijo], elem)) {
            array[hueco] = std::move(array[hijo]);
            hueco = hijo; hijo = 2 * hueco;
        }
        else break;
    }
    array[hueco] = std::move(elem);
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::monticulizar() {
    for (auto i = numElems / 2; i > 0; --i)
        hundir(i);
}

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
    int puntuacion_est; //prioridad estimada
};

bool operator>(Nodo const& a, Nodo const& b) {
    return a.puntuacion_est > b.puntuacion_est;
}


int calculoVoraz(vector<Cancion> const& canciones, int dMax, int k, int duracion1, int puntuacion1, int duracion2, int puntuacion2) {
    int hueco = 2*dMax - duracion1 - duracion2;
    float estimacion = puntuacion1 + puntuacion2;
    int j = k + 1;
    
    //solo canciones enteras
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
        //primera cara
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
        //segunda cara
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
        //no meter la cancion
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

bool resolver() {
    int nCanciones, dMax;
    cin >> nCanciones;
    if (nCanciones == 0) return false;
    cin >> dMax;
    resuelveCaso(nCanciones, dMax);
    return true;
}

int main() {
    while (resolver()) {}
    return 0;
}
