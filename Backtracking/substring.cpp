#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
    vector<vector<string>> ans;
    vector<string> temp;

    string s = "aab";
    int n = s.length();

    for (int i=0; i < n; i++) {
        for (int j=i; j < n; j++) {
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}