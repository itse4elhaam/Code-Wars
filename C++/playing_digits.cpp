#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int digPow(int n, int p) {

    int sq_sum = 0;
    string str_n = to_string(n);

    for (char c : str_n) {
        int digit = c - '0';
        sq_sum += pow(digit, p);
        cout << "square sum: " << sq_sum << endl;
        p++;
    }

    if (sq_sum % n == 0) {
        return sq_sum / n;
    }

    return -1;
}

int main() {
    
    cout << digPow(89, 1) << endl;

    // dotest(92, 1, -1);
    // dotest(46288, 3, 51);
    // dotest(114, 3, 9);
    return 0;
}