#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void patternCol(int col) {
    if (col == 0) return;
    cout << col + 1;
    patternCol(col - 1);
}

void patternRow(int r, int n) {
    if (r > n) return;
    patternCol(n);
    cout << "endl";
    cout << n << " ";
    patternRow(r+1, n);
}


int main() {
    int n = 4;
    patternRow(1, n);

    return 0;
}