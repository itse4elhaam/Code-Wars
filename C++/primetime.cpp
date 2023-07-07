#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(unsigned n) {
    int limit = ceil(sqrt(n)); // rounding it up

    for (int i = 2; i <= limit; i++) {

        if(n % i == 0 & i != n){
            return false;
        }
    }

    return true;
}

vector<unsigned> primeTimep(unsigned n) {
    vector<unsigned> primes;

    if(n < 2) return {};

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {

    vector<unsigned> result = primeTimep(11);
    cout << "The answer for 11 is: ";
    for (int prime : result) {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}
