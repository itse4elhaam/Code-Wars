#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> countChars(const string& str) {
    unordered_map<char, int> charCount;
    for (char c : str) {
        charCount[c]++;
    }
    return charCount;
}

bool scramble(const string& s1, const string& s2) {
    unordered_map<char, int> count = countChars(s1);
    for (char c:s2){
        if (count.find(c) != count.end() && count[c] > 0){
            count[c] --;
        }
        else{
            return false;
        }
    }
        return true;
}



int main() {
    
    cout << "Testing scramble()..." << endl;
    cout << "scramble(rkqodlw, world) = " << scramble("rkqodlw", "world") << endl;
    cout << "scramble(cedewaraaossoqqyt, codewars) = " << scramble("cedewaraaossoqqyt", "codewars") << endl;
    cout << "scramble(katas, steak) = " << scramble("katas", "steak") << endl;
    cout << "scramble(scriptjavx, javascript) = " << scramble("scriptjavx", "javascript") << endl;
    cout << "scramble(scriptingjava, javascript) = " << scramble("scriptingjava", "javascript") << endl;
    cout << "scramble(scriptsjava, javascript) = " << scramble("scriptsjava", "javascript") << endl;
    cout << "scramble(javscripts, javascript) = " << scramble("javscripts", "javascript") << endl;
    cout << "scramble(aabbcamaomsccdd, commas) = " << scramble("aabbcamaomsccdd", "commas") << endl;
    cout << "scramble(commas, commas) = " << scramble("commas", "commas") << endl;
    cout << "scramble(sammoc, commas) = " << scramble("sammoc", "commas") << endl;
    cout << "Done testing scramble()" << endl;    return 0;
}