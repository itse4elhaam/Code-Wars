#include <iostream>
#include <string>

using namespace std;

int square_digits(int num) {
	
  string str = to_string(num);

	string squared = "";
    for (char c : str) {
        int num = c - '0' ;
        int a = num * num ;
		squared += to_string(a) ;
    }
  
  
 return stoi(squared);
}


int main() {
    int n = 123568; 
    
	cout << square_digits(n) << endl;

    return 0;
}
