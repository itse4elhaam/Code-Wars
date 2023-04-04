#include <iostream>
#include <string>
#include <regex>
using namespace std;

std::string remove_parentheses(const std::string &str) {
    std::string result = str;
    bool found = true;
    while (found) {
        std::regex pattern("\\([^\\(\\)]*\\)");
        result = std::regex_replace(result, pattern, "");
        found = std::regex_search(result, pattern);
    }
    return result;
}

int main() {
  cout << remove_parentheses("example(unwanted thing)example") << "\n";
  cout << remove_parentheses("example(unwanted thing)example") << "\n";
  cout << remove_parentheses("example (unwanted thing) example") << "\n";
  cout << remove_parentheses("a (bc d)e") << "\n";
  cout << remove_parentheses("a(b(c))") << "\n";
  cout << remove_parentheses("hello example (words(more words) here) something") << "\n";
  cout << remove_parentheses("(first group) (second group) (third group)") << "\n";
}
