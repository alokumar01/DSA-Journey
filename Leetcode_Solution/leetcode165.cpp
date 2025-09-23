
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to extract one revision number from the version string
    // Example: from "1.23.4" if idx is at start, it will return 1, then move idx to next after '.'
    int checkRevision(string &v, int &idx) {
        int num = 0;

        // keep reading digits until we find '.' or end of string
        while (idx < v.size() && v[idx] != '.') {
            num = num * 10 + (v[idx] - '0');  // build number digit by digit
            idx++;
        }

        // skip the '.' if present (move index forward)
        if (idx < v.size() && v[idx] == '.') idx++;

        return num;  // return the revision number found
    }

    // Main function to compare two version numbers
    int compareVersion(string version1, string version2) {
        int left1 = 0; // pointer/index for version1
        int left2 = 0; // pointer/index for version2

        // Keep checking until both strings are fully processed
        while (left1 < version1.size() || left2 < version2.size()) {
            int firstRev = checkRevision(version1, left1);   // get next revision from version1
            int secondRev = checkRevision(version2, left2); // get next revision from version2

            // Compare revision numbers
            if (firstRev < secondRev) 
                return -1; // version1 < version2
            else if (firstRev > secondRev)
                return 1;  // version1 > version2
        }
        return 0; // versions are equal
    }
};


// 1. Problem Statement (What we want to do)

// We need to compare two version numbers given as strings.
// Example:

// "1.2" vs "1.10" → return -1 (since 2 < 10)
// "1.01" vs "1.001" → return 0 (since both mean 1.1)
// "1.0.5" vs "1.0.3" → return 1 (since 5 > 3)

// So basically, break versions into revisions separated by . and compare one by one.

// 2. Brute Force Idea

// Split both strings by . (using something like stringstream or manually).
// Convert each split part to integer.
// Compare one by one in order.
// If one string ends earlier, treat missing parts as 0.

// 👉 Problem: Splitting and storing all parts first uses extra memory.

// 3. Optimized Idea (Your Code’s Approach 👍)

// Instead of splitting everything at once:
// Use two pointers (left1, left2) to read numbers directly from the string.
// Extract one number at a time (using checkRevision).
// Compare immediately.
// Stop as soon as you find a difference.
// If both strings end without differences → they are equal.

// 👉 This avoids storing arrays of revisions, so it’s faster and memory-efficient.

// 4. How Your Code Works (Simple Steps)

// Start with two indexes (left1, left2) for each version string.

// Call checkRevision → it reads the next number until it finds a . or end of string.

// Compare the two numbers:

// If one is bigger → return result immediately.
// If equal → continue to next revision.
// If both versions finish and no difference found → return 0.
// 5. Time & Space Complexity

// Time Complexity: O(max(N, M)) where N and M are lengths of version1 and version2. (Each character is processed once)
// Space Complexity: O(1) (no extra storage, just a few variables).

// # Compare Version Numbers

// ## Problem
// Given two version numbers as strings, compare them:
// - Return `1` if version1 > version2
// - Return `-1` if version1 < version2
// - Return `0` if they are equal

// Example:


// Input: version1 = "1.01", version2 = "1.001"
// Output: 0


// ### Optimized (Implemented Here):
// - Use two pointers to read numbers directly from strings
// - Extract one revision at a time using `checkRevision`
// - Compare immediately
// - Stop early if difference found

// ## Complexity
// - Time: O(max(N, M))  
// - Space: O(1)  

// ## Code
// (then paste your commented code here)