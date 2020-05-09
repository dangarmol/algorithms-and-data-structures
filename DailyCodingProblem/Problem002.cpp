#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> solve(const vector<int> &a) {
   // Create and initialize output array.
   vector<int> out(a.size(), 1);
   
   if(a.size() == 1) {
      return a;
   }

   int fromRight = 1, fromLeft = 1;
   // Iterating the array right to left and left to right.
   for(int i = 0; i < a.size(); ++i) {

      fromLeft *= a[i];
      out[i + 1] *= fromLeft;

      fromRight *= a[a.size() - 1 - i];
      out[a.size() - 2 - i] *= fromRight;
   }

   return out;
}

int main() {
   vector<int> a;
   srand(time(NULL));

   for(int i = 0; i < 5; ++i) {
      a.push_back((rand() % 10) + 1); // Random number (1-10)
   }

   for(int i = 0; i < a.size(); ++i) {
      cout << a[i] << " ";
   }
   cout << endl;

   vector<int> solution = solve(a);

   for(int i = 0; i < solution.size(); ++i) {
      cout << solution[i] << " ";
   }
   cout << endl;

   return 0;
}