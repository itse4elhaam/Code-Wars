#include <iostream>
using namespace std;


int rental_car_cost(int d) {
    int total = d * 40;
    return d > 6 ? (total - 50) : (d > 2 ? (total - 20) : total);
}

int main() {
    
    cout << rental_car_cost(69) << endl;
    return 0;
}