#include <iostream>
#include <map>
#include <string>
using namespace std;

string convertLine(const string& str) {
    map<char, int> counter;
    string newStr;
    for (int i = 0; i < str.length(); i++) {
        counter[tolower(str[i])]++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (counter[tolower(str[i])] > 1) {
            newStr += ")";
        }
        else {
            newStr += "(";
        }
    }
    return newStr;
}
int main() {
    string str;
    printf("Enter line to transform:\n");
    getline(cin, str);
    cout << convertLine(str);
    return 0;
}
