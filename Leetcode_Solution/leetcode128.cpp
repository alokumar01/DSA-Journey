// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // set<int> s;
//         // more optimizee using unordered_set
//         unordered_set<int> s(nums.begin(), nums.end());

//         // for (int num : nums) { // use shorter way to fill the set like nums.begin(), nums.end()
//         //     s.insert(num);
//         // }

//         int longest = 0;
//         for (int data : s) {
//             if (s.find(data - 1) == s.end()) {
//                 int len = 1;
//                 int current = data;

//                 while (s.find(current + 1) != s.end()) {
//                     current++;
//                     len++;
//                 }

//                 longest = max(longest, len);
//             }
//         }

//         return longest;
//     }
// };

//approach, intuition
// [ Time taken: 31 m 23 s ]
// only start counting when you find the beginning of a sequence,
// This ensures each number is processed only once.

// in this question i have used the set, but use the unordered_set for performance because, set gives you (log n) while unordered give you o(1) lookup.

// unordered_set<int> s(nums.begin(), nums.end() );