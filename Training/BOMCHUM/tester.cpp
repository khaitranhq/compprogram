#include <bits/stdc++.h>
using namespace std;
const string NAME = "BOMCHUM";
const int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long L, long long R) {
  assert(L <= R);
  return L + rd() % (R - L + 1);
}

int main() {
  srand(time(NULL));
  for (int iTest = 1; iTest <= NTEST; iTest++) {
    ofstream inp((NAME + ".INP").c_str());
    
    // Test case generation for low constraints (≤ 100)
    int q;
    
    // Generate different test case patterns
    if (iTest <= 20) {
      // Small test cases: q ≤ 10, values ≤ 100
      q = Rand(1, 10);
    } else if (iTest <= 50) {
      // Medium test cases: q ≤ 50, values ≤ 100  
      q = Rand(10, 50);
    } else if (iTest <= 80) {
      // Large test cases: q ≤ 100, values ≤ 100
      q = Rand(50, 100);
    } else {
      // Edge cases: specific values for testing
      q = Rand(1, 100);
    }
    
    inp << q << "\n";
    
    // Generate bomb masses based on test case type
    for (int i = 1; i <= q; i++) {
      long long mass;
      
      if (iTest <= 20) {
        // Small values for initial tests
        mass = Rand(1, 20);
      } else if (iTest <= 40) {
        // Medium values 
        mass = Rand(1, 50);
      } else if (iTest <= 60) {
        // Larger values within constraint
        mass = Rand(1, 100);
      } else if (iTest <= 80) {
        // Mix of small and large values
        if (Rand(0, 1)) {
          mass = Rand(1, 10);  // Small values
        } else {
          mass = Rand(50, 100); // Large values
        }
      } else {
        // Edge cases: include perfect squares, primes, and special numbers
        if (iTest <= 85) {
          // Perfect squares up to 100
          long long sqrt_val = Rand(1, 10);
          mass = sqrt_val * sqrt_val;
        } else if (iTest <= 90) {
          // Prime numbers up to 100
          vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
          mass = primes[Rand(0, primes.size() - 1)];
        } else {
          // Powers of 2 up to 64
          int exp = Rand(0, 6);
          mass = 1LL << exp;
        }
      }
      
      inp << mass;
      if (i < q) inp << " ";
    }
    inp << "\n";
    
    inp.close();

    system(("./" + NAME + ".exe").c_str());
    system("./brute-force.exe");
    if (system(("diff -w " + NAME + ".OUT " + NAME + ".ANS").c_str()) != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      return 0;
    }
    cout << "Test " << iTest << ": CORRECT!\n";
  }
  return 0;
}
