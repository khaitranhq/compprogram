#include <iostream>
#include <fstream>
using namespace std;

/**
 * Calculates the sum of all positive divisors of a given number
 * @param n The number to find divisors for
 * @return Sum of all positive divisors of n
 */
long long sumOfDivisors(long long n) {
    long long sum = 0;
    
    // Brute force approach: check every number from 1 to n
    for (long long i = 1; i <= n; i++) {
        if (n % i == 0) {  // i is a divisor of n
            sum += i;
        }
    }
    
    return sum;
}

int main() {
    // Open input and output files
    ifstream input("BOMCHUM.INP");
    ofstream output("BOMCHUM.ANS");
    
    int q;  // number of bombs
    input >> q;
    
    // Process each bomb's mass
    for (int i = 0; i < q; i++) {
        long long mass;
        input >> mass;
        
        // Calculate destructive power (sum of all positive divisors)
        long long destructivePower = sumOfDivisors(mass);
        
        // Output the result
        output << destructivePower;
        if (i < q - 1) {
            output << " ";  // Space separator between numbers
        }
    }
    
    input.close();
    output.close();
    
    return 0;
}
