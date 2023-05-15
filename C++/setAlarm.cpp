#include <iostream>
using namespace std;

bool setAlarm(bool employed, bool on_vac){
    return (employed && !on_vac) ? true : false;
}


int main() {
    cout << setAlarm(true,false) << endl;   // 1
    cout << setAlarm(true,true) << endl;    // 0
    cout << setAlarm(false,true) << endl;   // 0
    cout << setAlarm(false,false) << endl;  // 0
    return 0;
}