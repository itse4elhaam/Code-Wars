#include <iostream>
#include <vector>

using namespace std;

// this function takes which number to find even or odd as a paramter
// if even is true it will give first even number else the first odd number
int getFirstNum(bool even, const std::vector<int>& numbers) {
    for (auto num : numbers) {
        if ((!even && num % 2 != 0) || (even && num % 2 == 0)) {
            return num;
        }
    }
}

int FindOutlier(vector<int> arr)
{
    int result;
    bool evenTrend;
    int evenCount = 0;
    int oddCount = 0;

    // checking the trend by simply checking whether odd count gets more than 1 first or even Count
    // did this because there can only be one outlier and rest will be either even or odd
    for(int n:arr){
        if(n % 2 == 0){
            evenCount ++;
        }
        else{
            oddCount ++;
        }
        if (evenCount > 1){
            evenTrend = true;
            break;
        }
        else if(oddCount < 1){
            evenTrend = false;
            break;
        }
    }

    cout << "evenCount: " << evenCount << endl;
    cout << "even Trend: " << evenTrend << endl;

    // giving it opposite of evenTrend because if we have evenTrend we want the first odd number and vice versa
    return getFirstNum(!evenTrend, arr);
}

int main() {
    
    vector<int> nums = { 4, 1, 3, 5, 9 };
    cout << "Outlier: " << FindOutlier(nums) << endl;
    return 0;
}