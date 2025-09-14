#include <iostream>
using namespace std;
#include <vector>

bool targetSubset(vector<int> &nums, int target, int n) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<target+1; j++) {
            int itemVal = nums[i-1];

            if(itemVal <= j) {
                //include with exclude
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            } else {
                //exclude
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][target] == target;
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 20;
    int n = nums.size();
    cout <<  targetSubset(nums, target, n);
    return 0;
}