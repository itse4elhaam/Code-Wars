#include <iostream>
#include <string>
using namespace std;

//  Time Complexity : O(n^2)

int find(char c)
{
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < 26; i++)
    {
        if (c == alpha[i])
        {
            return i + 1;
        }
    }
    return -1; // Return -1 if character is not found
}

string alphabet_position(const string &text)
{

    string positions = "";
    int lastIndex = text.length() - 1;
    for (int i = 0; i <= lastIndex; i++)
    {

        char c = tolower(text[i]);
        string pos = to_string(find(c));

        // checking for any non alpha characters
        if (pos == "-1"){ continue; }

        // making sure that I don't add spaces after the last character
        if (i == lastIndex)
        {
            positions += pos;
        }
        else{
            positions += pos + " ";
        } 
    }
    if (positions.back() == ' ')
    {
        positions.pop_back();
    }
    return positions;
}

int main() {
    cout << alphabet_position("The sunset sets at twelve o' clock.");
    return 0;
}