#include <iostream>
#include <utility>
#include <vector>
using namespace std;


unsigned int number(const vector<std::pair<int, int>>& busStops) {


    int ppl_added = 0; // will add each first index of each nested vector
    int ppl_left = 0;  // will add each second index of each nested vector 
    for (const pair<int, int>& stop : busStops){
        ppl_added += stop.first;
        ppl_left += stop.second;
    }
    return ppl_added - ppl_left;
}

int main() {
    
    cout << "left: " << number({{ 10,0 }, { 3,5 }, { 5,8}});
    return 0;
}