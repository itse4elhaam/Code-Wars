#include <string>
#include <iostream>
#include <vector>
using namespace std;

string likes(const vector<string> &names){
    string msg;
    int size = names.size();

    switch (size) {
        case 0:
            msg = "no one likes this";
            break;
        case 1:
            msg = names[0] + " likes this";
            break;
        case 2:
            msg = names[0] + " and " + names[1] + " like this";
            break;
        case 3:
            msg = names[0] + ", " + names[1] + " and " + names[2] + " like this";
            break;
        default:
            int others_count = size - 2;
            msg = names[0] + ", " + names[1] + " and " + std::to_string(others_count) + " others like this";
            break;
    }

  
    return msg;
}

int main() {

    vector<string> names = { "Alex", "Jacob", "Mark", "Max" };
    cout << likes(names) << endl;
    return 0;
}