#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <string>

using namespace std;

string printVector(const vector<int> &v) {
   if(v.size() == 0) {
      return "[]";
   }

   string result = "[";
   for (size_t i = 0; i < v.size() - 1; i++) {
      result += to_string(v[i]) + ", ";
   }
   result += to_string(v.back());
   result += "]";
   
   return result;
}

bool solve(const vector<int> &v, const int &target) {
   unordered_set<int> s;

   for(size_t i = 0; i < v.size(); ++i) {
      if(s.find(target - v[i]) == s.end()) {
         // No matching pair found.
         s.insert(v[i]);
      } else {
         // Found a suitable pair of values!
         return true;
      }
   }

   return false;
}

int main() {
   vector<int> v;
   srand(time(NULL));
   int target = rand() % 100; // Random target (0-99)

   for(size_t i = 0; i < 25; ++i) {
      v.push_back(rand() % 50); // Filling the vector with 25 random integers (0-49).
   }
   
   cout << "Target: " << target << endl;
   cout << "Numbers: " << printVector(v) << endl;

   if(solve(v, target)) {
      cout << "True" << endl;
   } else {
      cout << "False" << endl;
   }

   return 0;
}