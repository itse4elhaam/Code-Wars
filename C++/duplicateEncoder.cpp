//  https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/train/cpp

// ? Incomplete 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string get_dup_words(const string& word) {
    string copy = word;
    string dups = "";

    // it takes a word and searched it inside the string and adds it to the array if found.
    for (int i = 0; i < copy.length(); i++) {
        char to_be_searched = copy[i];
        if (dups.find(to_be_searched) != string::npos) {
            continue;
        }
        for (int j = 0; j < copy.length(); j++) {
            char w = copy[j];
            if (j == i) {
                continue;
            }

            if (to_be_searched == w) {
                dups += w;
                break;
            }
        }
    }
    return dups;
}

string duplicate_encoder(const string& word) {

    string copy = word;
    // convert string into lower case only way to convert the whole string
    transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
    cout << "lower case " << copy << endl;
    // fetching the duplicates in this string
    string dups = get_dup_words(copy);
    cout << "duplicates: " << dups << endl;

    // checking if no dups found, because in case of no dups the loop might give errors 
    if (dups.length() == 0) {
        cout << "Duplicates not found!!" << endl;
        string brackets(copy.length(),'(');
        return brackets ;
    }


    string brackets = "";
    for (char w:copy){

        // checking if the current word being serached is a dup or not
        bool repeat = false;
        for (char s : dups) {
            if (w == s) {
                repeat = true;
                cout << "comparison : " << w << " " << s << endl;   
                break;
            }
        }

        // doing this outside because we need to check for it even if it comes once in the whole array and if doesn't for the whole array then and only then we can add the other bracket
        if (repeat) {
                brackets += ')';

        }else{
                brackets += '(';
        }

    }

    return brackets;
}

int main() {
    // Basic tests using cout statements and if statements
    // string test_word = "din";
    // string expected_result = "(((";
    // string result = duplicate_encoder(test_word);
    // if (result == expected_result) {
    //     cout << "Test 1 Passed" << endl;
    // }
    // else {
    //     cout << "Test 1 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    // }
    //     cout << endl;

    // test_word = "recede";
    // expected_result = "()()()";
    // result = duplicate_encoder(test_word);
    // if (result == expected_result) {
    //     cout << "Test 2 Passed" << endl;
    // }
    // else {
    //     cout << "Test 2 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    // }
    //     cout << endl;

    string test_word = "Success";
    string expected_result = ")())())";
    string result = duplicate_encoder(test_word);
    if (result == expected_result) {
        cout << "Test 3 Passed" << endl;
    }
    else {
        cout << "Test 3 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    }
        cout << endl;

    // test_word = "CodeWarrior";
    // expected_result = "()(((())())";
    // result = duplicate_encoder(test_word);
    // if (result == expected_result) {
    //     cout << "Test 4 Passed" << endl;
    // }
    // else {
    //     cout << "Test 4 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    // }
        // cout << endl;

    // test_word = "Supralapsarian";
    // expected_result = ")()))()))))()(";
    // result = duplicate_encoder(test_word);
    // if (result == expected_result) {
    //     cout << "Test 5 Passed" << endl;
    // }
    // else {
    //     cout << "Test 5 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    // }
        // cout << endl;

    // test_word = "(( @";
    // expected_result = "))((";
    // result = duplicate_encoder(test_word);
    // if (result == expected_result) {
    //     cout << "Test 6 Passed" << endl;
    // }
    // else {
    //     cout << "Test 6 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    // }
        // cout << endl;

    // test_word = " ( ( )";
    // expected_result = ")))))(";
    // result = duplicate_encoder(test_word);
    // if (result == expected_result) {
    //     cout << "Test 7 Passed" << endl;
    // }
    // else {
    //     cout << "Test 7 Failed. Expected result: " << expected_result << ". Got: " << result << endl;
    // }
        // cout << endl;

    return 0;
}

