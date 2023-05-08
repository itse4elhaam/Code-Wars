#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> getPermutes(std::vector<int>& nums) {

    std::sort(nums.begin(), nums.end()); // sort the vector in ascending order

    vector<vector<int>> permutations;

    do {
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        permutations.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end())); 


    return permutations;
}

int main() {

    std::vector<int> nums = { 1, 2, 3 };
    
    vector<vector<int>> permutes = getPermutes(nums);

    for (const auto& inner : permutes) {
        for (const auto& val : inner) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
