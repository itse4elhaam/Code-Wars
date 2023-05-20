#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countSmileys(vector<string> arr)
{
    int smileCount = 0;
    for (int i = 0; i < arr.size(); i++) {

        string sm_face = arr[i];

        bool eyes = sm_face[0] == ':' || sm_face[0] == ';';
        bool nose = sm_face.length() == 3 ? sm_face[1] == '~' || sm_face[1] == '-' : true;
        bool face = sm_face[sm_face.length() - 1] == ')' || sm_face[sm_face.length() - 1] == 'D';

        if (eyes && face && nose) {
            smileCount++;
        }

    }

    return smileCount;
}

int main() {
    

    cout << countSmileys({":-D", ";~)"}) << endl;
    return 0;
}