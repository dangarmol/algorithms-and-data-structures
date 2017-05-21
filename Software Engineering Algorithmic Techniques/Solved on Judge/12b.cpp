#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class BreadthFirstPaths {
public:
	BreadthFirstPaths(size_t s, int d)
		: marked(10000), edgeTo(10000), distTo(10000), s(s), d(d) {
		//if (s >= 10000) throw std::invalid_argument("Vértice inexistente");
		bfs(s);
	}

	// Devuelve el número de aristas en el camino más corto a v
	size_t distance(size_t v) const {
		return distTo.at(v);
	}

private:
	std::vector<bool> marked;
	std::vector<size_t> edgeTo;   // edgeTo[v] = último vértice antes de llegar a v
	std::vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto
	size_t s;      
	int d;

	void bfs(size_t s) {
		bool encontrado = false;
		std::queue<size_t> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty() && !encontrado) {
			auto v = q.front(); q.pop();
			int w;
			for (int i = 0; i <= 2; ++i) {
				if (i == 0) w = (v + 1) % 10000;
				else if (i == 1) w = (v * 2) % 10000;
				else w = v / 3;
				if (!marked[w]) {
					edgeTo[w] = v;
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
					if (w == d) encontrado = true;
				}
			}
		}
	}

};

bool resuelve() {
	int inicial;
	
	cin >> inicial;
	if (!cin) return false;
	else {
		int resultado;

		cin >> resultado;
		BreadthFirstPaths b(inicial, resultado);
		cout << b.distance(resultado) << '\n';
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}