#include <iostream>
using namespace std;
#include <vector>

//recursion se catlan number 
int catlan(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += catlan(i) * catlan(n-i-1); 
    }

    return ans;
}

// this is same using dynamic programming memoization
int catlanMemo(int n, vector<int> &dp) { // o(n) top down approach
    if(n == 0 || n == 1) {
        return 1;
    }
    
    int ans = 0;
    if (dp[n] != -1) return dp[n];

    for (int i=0; i<n; i++) {
        ans += catlanMemo(i, dp) * catlanMemo(n-i-1, dp); 
    }

    return dp[n] = ans;
}

// catalans using tabulation 
int catlanTabu(int n) { // o(n^2) bottom up approach
    if(n == 0 || n == 1) {
        return 1;
    }
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++) { // this loop, is for which value we want to calculate catlan
        for(int j=0; j<i; j++) { // then here we are calculating the catlan for that number 
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}


int main() {
    int n = 4;
    // cout << catlan(n) << endl; // recursion
    // vector<int> dp(n+1, -1); Memoization
    // cout << catlanMemo(n, dp) << endl; Memoization
    cout << catlanTabu(n) << endl; //Tabulation
    return 0;
}