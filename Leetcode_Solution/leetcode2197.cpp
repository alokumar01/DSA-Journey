#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach my thinking style(NOT CORRECT)
// int GCD(int x, int y) {
//     if (y == 0) return x;
//     return GCD(y, x % y);
// }

// long long LCM(int x, int y) {
//    return  (x / GCD(x, y)) * y;
// }

// vector<int> replaceNonCoprimes(vector<int>&nums) {
//     int n = nums.size();

//     for (int i=0; i<n; i++) {
//         for (int j=i+1; j<n; j++) {
//             if (GCD(nums[i], nums[j]) > 1) {
//                 break;
//             } else {
//                 nums.erase(nums.begin() + i, nums.begin() + j + 1);
//                 nums.insert(nums.begin() + i, LCM(nums[i], nums[j]));
//             }
//         }
//     }

//     return nums;
// }


// Optimized Approach
// TC- O(n^2 . log M) SC- O(1)
int GCD(int x, int y) {
    if (y == 0) return x;
    return GCD(y, x % y);
}

long long LCM(int x, int y) {
    return 1LL * x / GCD(x, y) * y;
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    int i = 0;
    while (i < (int)nums.size() - 1) {
        int g = GCD(nums[i], nums[i + 1]);
        if (g > 1) {
            long long l = LCM(nums[i], nums[i + 1]);
            nums[i] = l;                          
            nums.erase(nums.begin() + i + 1);
            if (i > 0) i--; 
        } else {
            i++;
        }
    }
    return nums;
}

int main() {
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
    vector<int> result = replaceNonCoprimes(nums);

    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
