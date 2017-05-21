#include <iostream>
#include <vector>
#include <algorithm>

#include "PriorityQueue.h"

using namespace std;

class Par {
private:
	int inicio;
	int fin;

public:
	Par(int i, int f) {
		inicio = i;
		fin = f;
	}

	bool operator< (const Par &otro) const {
		if (inicio < otro.inicio) return true;
		else {
			if (inicio == otro.inicio) {
				if (fin < otro.fin) return true;
				else return false;
			}
			else return false;
		}
	}

	int getInicio() const {
		return inicio;
	}

	int getFin() const {
		return fin;
	}
};

int vorazConferencias(const vector<Par> &candidatos) {
	int salas = 1;

	if (candidatos.size() == 0) return 0;
	
	PriorityQueue<int> colaTiempos(candidatos.size());
	colaTiempos.push(candidatos[0].getFin());

	for (int i = 1; i < candidatos.size(); ++i) {
		if (candidatos[i].getInicio() < colaTiempos.top()) {
			salas++;
			
		}
		else {
			colaTiempos.pop();
		}
		colaTiempos.push(candidatos[i].getFin());
	}

	return salas;
}

void resuelve(const int numConferencias) {
	vector<Par> conferencias;

	for (int i = 0; i < numConferencias; ++i) {
		int inicio, fin;

		cin >> inicio >> fin;
		conferencias.push_back(Par(inicio, fin));
	}
	sort(conferencias.begin(), conferencias.end());
	cout << vorazConferencias(conferencias) << '\n';
	
}

int main() {
	int conferencias;

	cin >> conferencias;
	while (conferencias > 0) {
		resuelve(conferencias);
		cin >> conferencias;
	}
}