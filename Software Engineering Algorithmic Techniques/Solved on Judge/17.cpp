//Grupo TAIS14
//Juan Alberto Camino Saez
//Daniel García Molero

#include <iostream>
#include <vector>
#include <string>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;

class CaminoMinimo {
private:
    vector<AristaDirigida<size_t>> edgeTo;
    vector<size_t> distTo;
    int segundos;
    size_t v;
    size_t destino;
    
    void relax(const AristaDirigida<size_t> &e, IndexPQ<size_t> &pq)
    {
        size_t v = e.from(), w = e.to();
        if (distTo[w] > distTo[v] + e.valor())
        {
            distTo[w] = distTo[v] + e.valor();
            edgeTo[w] = e;
            pq.update(w, distTo[w]);
        }
    }
    
public:
    
	//Esta funcón tiene el coste del algoritmo de Dijstra, que tiene coste O(E * log(V))
    CaminoMinimo(GrafoDirigidoValorado<size_t> &graph, const size_t &origen, const size_t &destination, const int &s)
    {
        edgeTo = vector<AristaDirigida<size_t>>(graph.V());
        distTo = vector<size_t>(graph.V());
        IndexPQ<size_t> pq(graph.V());
        segundos = s;
        destino = destination;
        
        for (int i = 0; i < graph.V(); i++)
            distTo[i] = 10000000;
        distTo[origen] = 0;
        pq.push(origen, 0);
        v = -1;
        while (!pq.empty() && v != destino)
        {
            v = pq.top().elem;
            pq.pop();
            if (v != destino) {
                for (AristaDirigida<size_t> e : graph.adj(v))
                    relax(e, pq);
            }
        }
    }
    
    size_t getSegundos() {
        if (v != destino) {
            return -1;
        }
        return segundos + distTo[destino];
    }
};

size_t resolverCaso(GrafoDirigidoValorado<size_t> &graph, const int &segundosIniciales) {
    CaminoMinimo c(graph, 0, graph.V() - 1, segundosIniciales);
    return c.getSegundos();
}

void resolver(int nPages) {
    size_t time;
    GrafoDirigidoValorado<size_t> graph = GrafoDirigidoValorado<size_t>(nPages);
    AristaDirigida<size_t> link;
    vector<int> loadingTimes;
    int auxTime;
    int nConnections, a, b, clickTime;
    for (int i = 0; i < nPages; ++i) {
        cin >> auxTime;
        loadingTimes.push_back(auxTime);
    }
    cin >> nConnections;
    for (int j = 0; j < nConnections; ++j) {
        cin >> a >> b >> clickTime;
        link = AristaDirigida<size_t>(a - 1, b - 1, clickTime + loadingTimes[b - 1]);
        graph.ponArista(link);
    }
    time = resolverCaso(graph, loadingTimes[0]);
    if (time == -1) {
        cout << "IMPOSIBLE" << endl;
        return;
    }
    cout << time << endl;
}

int main() {
    int nPages;
    cin >> nPages;
    while (nPages > 0) {
        resolver(nPages);
        cin >> nPages;
    }
    return 0;
}