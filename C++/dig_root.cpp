#include <iostream>
#include <string>
using namespace std;

int digital_root(int n){
    
    int total = 0;
    
    // this how you can iterate over an integer in the opposite order
    while (n > 0){
        total += n % 10;
        n /= 10;
    }
    
    // if we have not obtained the one root we'll call the function again.
    if (total > 9){
        return digital_root(total);
    }

    return total;
}

int main() {
    
    cout << digital_root(942) << endl;
    return 0;
}