#include <iostream>
#include <string>
using namespace std;

int romanToInt(char r)
{
    return (r == 'I') ? 1 : (r == 'V') ? 5
                        : (r == 'X')   ? 10
                        : (r == 'L')   ? 50
                        : (r == 'C')   ? 100
                        : (r == 'D')   ? 500
                        : (r == 'M')   ? 1000
                                       : 0;
}

int solution(string roman)
{

    int total = 0;
    int i = 0;
    for (char r : roman)
    {
        if (romanToInt(r) < romanToInt(roman[i + 1])){
            total -= romanToInt(r);
        }
        else
        {
            total += romanToInt(r);
        }

        i++;
    }

    return total;
}

int main()
{

    cout << "Expected: 21" << endl;
    cout << "Actual: " << solution("XXI") << endl;
    cout << "Expected: 1" << endl;
    cout << "Actual: " << solution("I") << endl;
    cout << "Expected: 4" << endl;
    cout << "Actual: " << solution("IV") << endl;
    cout << "Expected: 2008" << endl;
    cout << "Actual: " << solution("MMVIII") << endl;
    cout << "Expected: 1666" << endl;
    cout << "Actual: " << solution("MDCLXVI") << endl;
    cout << endl;

    return 0;
}