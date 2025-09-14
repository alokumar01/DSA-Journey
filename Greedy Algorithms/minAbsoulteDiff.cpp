#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void minAbsDiff(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int minSum = 0;
    for(int i=0; i<A.size(); i++) {
        minSum += abs(A[i] - B[i]);
    }
    
    cout << "Minimum Absoulte Diff: " << minSum << endl;
}


int main() {
    vector<int> A = { 4, 1, 8, 7};
    vector<int> B = { 2, 3, 6, 5};

    minAbsDiff(A, B);
    return 0;
}