#include <iostream>
#include <string>
using namespace std;

string printerError(const string &s){
      
    int count = 0;
    for (char c:s){
        if (c > 'm') {
            count ++;
        }
    } 
    return to_string(count) + "/" + to_string(s.length());
};

int main() {
    
    string s = "vbnbvnbvnaaaammmmmmmuuuuuuu";

    cout << "Error ratio: " << printerError(s) << endl;
    return 0;
}