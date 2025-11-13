#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int result = 0;

        unordered_set<char> store;
        for(int right=0; right<n; right++) {
            while(store.contains(s[right])) {
                store.erase(s[left]);
                left++;
            }
            store.insert(s[right]);
            result = max(result, right-left+1);
        }

        return result;
    }
};


// Revision - SLIDING WINDOWS VARIABLE SIZING
// while duplicate → shrink
// 🔹 insert new char
// 🔹 update max length

// TC: O(n)
// SC: O(k) ≤ O(n)

// This is how all variable-size sliding windows work.