// 99 => W 18
// 100 => W 1
// So in the list 100 will come before 99
// given the string with the weight of fft members in normal order, can you give this string ordered by weight of these numbers
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string order_weight(const string str){

    auto num = "";
    int total = 0;
    vector<int> nums;
    vector<int> total_arr;
    // creating a vector of of all of the original string and another vector that holds the sum of each number.
    for(int i = 0; i < str.length(); i++){
        cout << i << endl;
        if (str[i] == ' '){
            cout << "num: " << num << endl;
            nums.push_back(stoi(num));
            total_arr.push_back(total);
            num = "";
            total = 0;
            continue;
        }
        num += str[i];
        total += str[i] - '0';
        cout << "num: " << num << endl;
        cout << "total: " << total << endl;
    }

    cout << "nums Length: " << nums.size() << endl;
    cout << "total_arr Length: " << total_arr.size() << endl;
}


int main() {
    
    // vector<string> str = {"56","65","74","100","99","86","68","180","90"};
    string str = "56 65 74 100 99 86 68 180 90";

    string output = order_weight(str);
    // number of weight becomes:
        // {"100","180","90","56","65","74","68","86","99"}
    
    return 0;
}