#include <iostream>
using namespace std;

int bouncingBall(double h, double bounce, double window){
    if (h < 0 || bounce <= 0 || bounce >= 1 || window >= h) {
        return -1;
    }
    int total = 1;
    while (true) {
        h *= bounce;
        if (h <= window) {
            return total;
        }
        total += 2;
    }

}

int main() {
    
    cout << bouncingBall(30, 0.66, 1.5) << endl;
    return 0;
}