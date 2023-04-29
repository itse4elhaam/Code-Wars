//  https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/train/cpp

// ? Incomplete 
#include <iostream>
#include <string>
using namespace std;

string duplicate_encoder(const string &word){

    string brackets = "";
    int i = 0;
    string copy = word; // make a copy of the original string
    for (char w : word)
    {
        copy.erase(0, i); // erase the first i characters from the copy
        if (copy.find(w) != string::npos)
        {
            brackets += ')';
        }
        else
        {
            brackets += '(';
        }
        i++;
    }
    return brackets;
}

int main()
{
    
    cout << duplicate_encoder("recede") << endl;
    return 0;
}
