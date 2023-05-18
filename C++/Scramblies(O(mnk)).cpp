#include <iostream>
#include <string>
using namespace std;

bool scramble(const string& s1, const string& s2) {
    
    int found_count = 0;
    string scrambled = s1;
    string org = s2;

    for (char o : org) {
        for (int i = 0; i < scrambled.length(); i++) { 
            if (scrambled[i] == o) {
                found_count++;
                scrambled.erase(i , 1);
                break;
            }
        }

        if(org.length() - found_count > scrambled.length()) {
            break;
        }
    }


    if (found_count != org.length()) {
        return false;
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