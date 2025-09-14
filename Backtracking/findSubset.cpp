#include <iostream>
using namespace std;

void findSubset(string str, string subset) {
    if(str.size() == 0) {
        cout << subset << endl;
        return;
    }

    char ch = str[0];
    // yes conditions
    findSubset(str.substr(1, str.size()-1), subset+ch);
    // no conditions
    findSubset(str.substr(1, str.size()-1), subset);
}

int main() {
    string str = "abc";
    string subset = "";
    findSubset(str, subset);
    return 0;
}