#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
#include <map>


int main() {
    map<string, int> m;
    // map use tab karo jab tumhare liye order matter karta ho the use map

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["UK"] = 20;

    for(pair<string, int> country : m) {
        cout << country.first << "," << country.second << endl;
    }

    return 0;
}