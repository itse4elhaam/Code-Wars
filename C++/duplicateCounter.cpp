#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

// PREP

// p : chars
// I will loop over all of the chars and
// then I will have an inner loop that will compare the char
// to the whole array and as soon the count reaches two I will break it and add one to the reps
// each time an alphabet is found, add it to the dups vector
// each time before counting the reps I will check if the character is found in the vector

char* toLowerCase(const char* str) {
    if (str == nullptr) {
        return nullptr;
    }

    size_t length = std::strlen(str);
    char* result = new char[length + 1];

    for (size_t i = 0; i < length; i++) {
        result[i] = std::tolower(str[i]);
    }

    result[length] = '\0'; // Add null-terminator

    return result;
}

bool foundInArray(const vector<char> arr, char element) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

size_t duplicateCount(const char* in)
{
    in = toLowerCase(in);
    vector<char> duplicates;
    size_t reps = 0;

    if (in == nullptr || strcmp(in, "") == 0 || strcmp(in, " ") == 0) {
        return 0;
    }

    for (const char* current = in; *current != '\0'; current++) {
        const char c = *current;
        int count = 0;

        //cout << "Searching for: " << c << endl;
        //cout << "RELEVANT DEBUGGING STATEMENTS:" << endl;

        for (const char* inner_current = in; *inner_current != '\0'; inner_current++) {
            const char inner_c = *inner_current;

            //cout << "checking count for each c: " << c << ", count: " << count << endl; 

            if (c == inner_c) {
                count++;
                //cout << "the current count is: " << count << endl;
                //cout << "the inner c is :" << inner_c << endl;
                //cout << "the outer c is :" << c << endl;
                //cout << endl;
            }

            if (count > 1 && !(foundInArray(duplicates, c))) {
                duplicates.push_back(c);
                //cout << "The character which has been duplicated is: " << c << " and the count is: " << count << endl;
                //cout << endl;
                //cout << endl;
                reps++;
                count = 0;
                break;
            }
            else if (*current == '\0') {
                count = 0;
                break;
            }

        }

    }


    return reps;
}


int main() {

    cout << "The Number of dups here are: " << duplicateCount("aabbcde") << endl;
    cout << "The Number of dups here are: " << duplicateCount("aabBcde") << endl;
    cout << "The Number of dups here are: " << duplicateCount("Indivisibility") << endl;
    cout << "The Number of dups here are: " << duplicateCount("Indivisibilities") << endl;
    cout << "The Number of dups here are: " << duplicateCount("ABBA") << endl;
    return 0;
}