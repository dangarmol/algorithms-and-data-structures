#include <iostream>
#include <vector>
#include <algorithm>

#include "PriorityQueue.h"

using namespace std;

class Par {
private:
	int occidental;
	int oriental;

public:
	Par(int oc, int ori) {
		occidental = oc;
		oriental = ori;
	}

	bool operator< (const Par &otro) const {
		if (occidental < otro.occidental) return true;
		else {
			if (occidental == otro.occidental) {
				if (oriental < otro.oriental) return true;
			}
			return false;
		}
	}

	int getOccidental() const {
		return occidental;
	}

	int getOriental() const {
		return oriental;
	}
};

//El coste de la funcion voraz es del orden de O(n), donde n es el numero de elementos del vector apartamentos.
//Sin embargo, ya que se ordena el vector antes de entrar en la funcion, el coste seria de orden O(n * (log n)), donde
//n es el numero de elementos del vector apartamentos.
int vorazApartamentos(const vector<Par> &apartamentos) {
	int numPuentes = 1;

	if (apartamentos.size() == 0) return 0;

	int menosOriental = apartamentos[0].getOriental();

	for (int i = 1; i < apartamentos.size(); ++i) {
		if (apartamentos[i].getOccidental() >= menosOriental){
			numPuentes++;
			menosOriental = apartamentos[i].getOriental();
		}
		else {
			if (apartamentos[i].getOriental() < menosOriental) {
				menosOriental = apartamentos[i].getOriental();
			}
		}
		
	}
	return numPuentes;
}

void resuelve(const int a) {
	vector <Par> apartamentos;

	for (int i = 0; i < a; ++i) {
		int oc, ori;

		cin >> oc >> ori;
		apartamentos.push_back(Par(oc, ori));
	}
	sort(apartamentos.begin(), apartamentos.end());
	cout << vorazApartamentos(apartamentos) << '\n';
}

int main() {
	int apartamentos;

	cin >> apartamentos;
		while (apartamentos > 0) {
			resuelve(apartamentos);
			cin >> apartamentos;
		}
	return 0;
}
