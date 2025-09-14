#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
int main() {

    // use tab karo jab order matter nahi hai tumhare liye, aur jyda priority time complexity hai then tum use karo unordered map 

    unordered_map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["us"] = 50;
    for(pair<string, int> country : m) {
        cout << country.first << "," << country.second << endl;
    }

    return 0;
}