#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int main() {
    map<int, string> m;
    m[101] = "Abhi";
    m[102] = "Radhe";
    m[103] = "ram";

    cout << m[101] << endl;

    cout << m.count(101) << endl;
    cout << m.count(100) << endl;

    for(auto it : m) {
        cout << it.first << " " << it.second;
    }

    return 0;
}