#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void indianCoins(vector<int>& coins, int V) {
    int n = coins.size();

    int ans = 0;
    for(int i=n-1; i >= 0 && V > 0; i--) {
        if (V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];
        }
    }

    cout << "Min Coins: " << ans << endl;
} 


int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 8001;

    indianCoins(coins, V);
    return 0;
}