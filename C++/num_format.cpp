#include <iostream>
#include <string>
using namespace std;

string numberFormat(long long n) {

    bool negative = n < 0;

    // if too short to be formatted just return as string
    if (n < 1000 && n > -1000) {
        return to_string(n);

    }

    // checking because if negative we cannot include it in the algo
    if (negative) {
        n = n * -1;
    }

    string formatted = "";
    string num = to_string(n);
    int size = num.length();

    // * each if statements follows this line wise
    // - 1- checking if its in the form of pairs of three, if yes then we can just add commas after every 3 ones
    // - 2- if its not then we need to check if there is one extra digit that's stopping it from becoming pairs of 3 or two
    // - 3- if two => comma after first two digits else if 1 then comma after first digit
    bool pairs_of_3 = size % 3 == 0;

    cout << "Size: " << size << endl;
    cout << pairs_of_3 << endl;

    // 1
    if (pairs_of_3) {
        cout << "Valid Pair" << endl;
        for (int i = 0; i < size; i++) {
            bool end = i == size - 1;

            if (!end && i != 0 && i % 3 == 0) {
                formatted += ',';
            }
            formatted += num[i];
        }
    }
    // 2
    else if(!pairs_of_3 && (size - 2) % 3 == 0) {
        cout << "invalid Pair" << endl;
        for (int i = 0; i < size; i++) {
            bool end = i == size - 1;

            if (!end && (i - 2) % 3 == 0) {
                formatted += ',';
                cout << "i : " << i << endl;
            }
            formatted += num[i];

        }
    }

    // 3 
    else {
        // cout << "invalid Pair" << endl;
        for (int i = 0; i < size; i++) {
            bool end = i == size - 1;

            if (!end && (i - 1) % 3 == 0) {
                formatted += ',';
            }
            formatted += num[i];
        }
    }

    // if negative then put it in correct form.
    if (negative) {
        formatted = '-' + formatted;
    }

    return formatted;
}

int main() {


    cout << numberFormat(100000) << endl;
    cout << numberFormat(5678545) << endl;
    cout << numberFormat(-420902) << endl;
    cout << numberFormat(-15941077) << endl;
    cout << numberFormat(-3) << endl;
    cout << numberFormat(3) << endl;
    cout << numberFormat(-1004) << endl;
    cout << numberFormat(39684613937) << endl;
    return 0;
}