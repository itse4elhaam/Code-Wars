// #include <iostream>
// #include <vector>
// using namespace std;


// class DirReduction
//     {
//     public:
//         static bool hasMatchingPair(const vector<string>& arr) {
//             for (int i = 0; i < arr.size() - 1; i++) {
//                 if (arr[i] + arr[i + 1] == "NORTHSOUTH" || arr[i] + arr[i + 1] == "SOUTHNORTH" ||
//                     arr[i] + arr[i + 1] == "EASTWEST" || arr[i] + arr[i + 1] == "WESTEAST") {
//                     return true;
//                 }
//             }
//             return false;
//         }


//         static vector<string> dirReduc(vector<string>& arr){

//             bool loop = true;
//             int c = 1;
//             while (loop) {

//                 // I'm trying to make loop true even if matching pair is found once in the loop
//                 for (int i = 0; i < arr.size(); i++) {

//                     bool remove = (arr[i] + arr[i + 1] == "NORTHSOUTH" || arr[i] + arr[i + 1] == "SOUTHNORTH" ||
//                         arr[i] + arr[i + 1] == "EASTWEST" || arr[i] + arr[i + 1] == "WESTEAST"); 

//                     if (remove) {
//                         cout << "Found matching pair: " << i << endl;
//                         arr.erase(arr.begin() + i, arr.begin() + i + 2); // this is two because we have to give range
//                         loop = true;
//                     }
//                     cout << "New Array size: " << arr.size() << endl;

//                     cout << "{ ";
//                     for (int j = 0; j < arr.size(); j++) {
//                         cout << arr[j];
//                         if (j != arr.size() - 1) {
//                             cout << ", ";
//                         }
//                     }
//                     cout << " }" << endl;

//                 }
//                 c++;
//                 loop = hasMatchingPair(arr);
//             }
//             cout << "While ran: " << c << " times" << endl;
//             return arr;
//         };
//     };

#include <iostream>
#include <vector>
using namespace std;


class DirReduction
    {
    public:
        static bool hasMatchingPair(const vector<string>& arr) {
            for (int i = 0; i < arr.size() - 1; i++) {
                if (arr[i] + arr[i + 1] == "NORTHSOUTH" || arr[i] + arr[i + 1] == "SOUTHNORTH" ||
                    arr[i] + arr[i + 1] == "EASTWEST" || arr[i] + arr[i + 1] == "WESTEAST") {
                    return true;
                }
            }
            return false;
        }


        static vector<string> dirReduc(vector<string>& arr){

            bool loop = true;

                // I'm trying to make loop true even if matching pair is found once in the loop
                for (int i = 0; i < arr.size(); i++) {
                    bool remove = (arr[i] + arr[i + 1] == "NORTHSOUTH" || arr[i] + arr[i + 1] == "SOUTHNORTH" ||
                        arr[i] + arr[i + 1] == "EASTWEST" || arr[i] + arr[i + 1] == "WESTEAST"); 
                    if (remove) {
                        arr.erase(arr.begin() + i, arr.begin() + i + 2); // this is two because we have to give range
                        loop = true;
                    }
                }
            loop = hasMatchingPair(arr);

            if (loop){
                return dirReduc(arr);
            }

                return arr;
        };
    };

int main() {

    vector<string> d1 = { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
    vector<string> ans1 = DirReduction::dirReduc(d1);
    vector<string> sol1 = { "WEST" };

    if (ans1 == sol1) {
        std::cout << "Test 1 passed.\n" << endl;
    }
    else {
        std::cout << "Test 1 failed.\n" << endl;
    }

    vector<string> d2 = { "NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH" };
    vector<string> ans2 = DirReduction::dirReduc(d2);
    vector<string> sol2 = { "NORTH" };

    if (ans2 == sol2) {
        std::cout << "Test 2 passed.\n" << endl;
    }
    else {
        std::cout << "Test 2 failed.\n" << endl;
    }

    cout << "First test: " << endl;
    for(string d : ans1){
        cout << d << "\n";
    }
    cout << "Second test: " << endl;
    for(string d : ans2){
        cout << d << "\n";
    }
    // Test 3: No directions to reduce
    vector<string> d3 = { "NORTH", "EAST", "SOUTH", "WEST" };
    vector<string> ans3 = DirReduction::dirReduc(d3);
    vector<string> sol3 = { "NORTH", "EAST", "SOUTH", "WEST" };
    if (ans3 == sol3) {
        std::cout << "Test 3 passed.\n" << endl;
    }
    else {
        std::cout << "Test 3 failed.\n" << endl;
    }

    // Test 4: Directions that cancel each other out completely
    vector<string> d4 = { "NORTH", "SOUTH", "EAST", "WEST" };
    vector<string> ans4 = DirReduction::dirReduc(d4);
    vector<string> sol4 = {};
    if (ans4 == sol4) {
        std::cout << "Test 4 passed.\n" << endl;
    }
    else {
        std::cout << "Test 4 failed.\n" << endl;
    }

    // Test 5: Long sequence of directions that reduce to one
    vector<string> d5 = { "NORTH", "SOUTH", "EAST", "WEST", "NORTH", "SOUTH", "EAST", "WEST", "NORTH", "SOUTH", "EAST", "WEST", "NORTH", "SOUTH", "EAST", "WEST" };
    vector<string> ans5 = DirReduction::dirReduc(d5);
    vector<string> sol5 = { "NORTH" };
    if (ans5 == sol5) {
        std::cout << "Test 5 passed.\n" << endl;
    }
    else {
        std::cout << "Test 5 failed.\n" << endl;
    }

    // Test 6: Long sequence of directions that reduce to multiple
    vector<string> d6 = { "NORTH", "SOUTH", "EAST", "WEST", "NORTH", "SOUTH", "EAST", "WEST", "NORTH", "SOUTH", "EAST", "WEST", "NORTH", "SOUTH", "EAST", "WEST", "EAST", "WEST" };
    vector<string> ans6 = DirReduction::dirReduc(d6);
    vector<string> sol6 = { "NORTH", "EAST", "WEST" };
    if (ans6 == sol6) {
        std::cout << "Test 6 passed.\n" << endl;
    }
    else {
        std::cout << "Test 6 failed.\n" << endl;
    }

    // Test 7: Random directions that reduce to one
    vector<string> d7 = { "NORTH", "SOUTH", "SOUTH", "SOUTH", "WEST", "WEST", "WEST", "WEST", "NORTH" };
    vector<string> ans7 = DirReduction::dirReduc(d7);
    vector<string> sol7 = { "WEST" };
    if (ans7 == sol7) {
        std::cout << "Test 7 passed.\n" << endl;
    }
    else {
        std::cout << "Test 7 failed.\n" << endl;
    }

    // Test 8: Random directions that reduce to multiple
    vector<string> d8 = { "NORTH", "EAST", "SOUTH", "WEST", "SOUTH", "SOUTH", "EAST", "EAST", "WEST", "WEST", "NORTH" };
    vector<string> ans8 = DirReduction::dirReduc(d8);
    vector<string> sol8 = { "SOUTH", "EAST", "WEST"};

    if (ans8 == sol8) {
        std::cout << "Test 8 passed.\n" << endl;
    }
    else {
        std::cout << "Test 8 failed.\n" << endl;
    }

    // Test 9: All directions are in one line
    vector<string> d9 = { "NORTH", "NORTH", "NORTH", "NORTH", "NORTH" };
    vector<string> ans9 = DirReduction::dirReduc(d9);
    vector<string> sol9 = { "NORTH" };

    if (ans9 == sol9) {
        std::cout << "Test 9 passed.\n" << endl;
    }
    else {
        std::cout << "Test 9 failed.\n" << endl;
    }

    // Test 10: No opposite directions, but cannot be reduced
    vector<string> d10 = { "NORTH", "EAST", "NORTH", "EAST", "SOUTH", "WEST" };
    vector<string> ans10 = DirReduction::dirReduc(d10);
    vector<string> sol10 = { "NORTH", "EAST", "NORTH", "EAST", "SOUTH", "WEST" };

    if (ans10 == sol10) {
        std::cout << "Test 10 passed.\n" << endl;
    }
    else {
        std::cout << "Test 10 failed.\n" << endl;
    }

    return 0;
}