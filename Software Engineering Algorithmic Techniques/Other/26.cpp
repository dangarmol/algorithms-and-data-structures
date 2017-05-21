#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Range {
private:
	int minReach;
    int maxReach;

public:
	Range(int min, int max) {
		minReach = min;
        maxReach = max;
	}

	bool operator< (const Range &otro) const {
        if (minReach < otro.minReach) {
            return true;
        } else if (minReach == otro.minReach) {
            return maxReach > otro.maxReach;
        }
        return false;
	}

	int getMinReach() const {
		return minReach;
	}
    
    int getMaxReach() const {
        return maxReach;
    }
};

//Esta funcion comprueba los restaurantes desde el primero y viendo los que va siendo necesario enlazar
//para que no quede ningun hueco en la calle. Para ello empieza por el restaurante i + 1 (siendo i el
//restaurante por el que va contando en el primer bucle) y llega hasta el momento en el que el
//restaurante enlaza hasta el final de la calle o bien deja de enlazar con el i.
//En cada bucle va viendo hasta donde alcanzan los restaurantes que se solapan con el restaurante i y se
//queda con el que mas lejos llega. Si alguno de ellos llegan a cubrir hasta la longitud de la calle,
//rompe todos los bucles y devuelve los que haya considerado necesarios hasta este momento.
int restaurantsGreedy(const vector<Range> &restaurants, const int &length) {
	int needed = 1;
    int frontCover;
    int frontIndex = 0;

	if (restaurants.size() == 0 || restaurants[0].getMinReach() != 1)
        return -1;

    frontCover = restaurants[0].getMaxReach();
    for (int i = 0; i < restaurants.size(); ++i) {
        if (frontCover == length)
            break;
        if (i < frontIndex)
            continue;
        for (int j = i + 1; j < restaurants.size(); ++j) {
            if (restaurants[frontIndex].getMaxReach() < restaurants[j].getMinReach())
                return -1;
            if (restaurants[j].getMinReach() <= restaurants[i].getMaxReach()) {
                frontCover = max(restaurants[j].getMaxReach(), frontCover);
                if (restaurants[j].getMaxReach() >= frontCover)
                    frontIndex = j;
            }
            if (restaurants[j].getMinReach() > restaurants[i].getMaxReach() || frontCover == length)
                break;
        }
        needed++;
    }
	return int(restaurants.size() - needed);
}

bool resuelve() {
	int length;
	cin >> length;
	if (!cin) return false;
	else {
		int numRest;
		vector<Range> restaurants;
		cin >> numRest;
		for (int i = 0; i < numRest; ++i) {
			int pos, inf, min, max;
			cin >> pos >> inf;
            min = pos - inf;
            max = pos + inf;
            if (min < 1) {
                min = 1;
            }
            if (max > length) {
                max = length;
            }
			restaurants.push_back(Range(min, max));
		}
		sort(restaurants.begin(), restaurants.end());
		cout << restaurantsGreedy(restaurants, length) << '\n';
		return true;
	}
}

int main() {
	while (resuelve()) {}
	return 0;
}
