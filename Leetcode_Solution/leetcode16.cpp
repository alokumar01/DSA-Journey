class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closetSum = nums[0] + nums[1] + nums[2];

        for(int i=0; i<nums.size()-2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(sum - target) < abs(closetSum - target)) {
                    closetSum = sum;
                }

                if (sum < target) 
                    left++;
                else if (sum > target)
                    right--; 
                else
                    return sum;

            }
        }

        return closetSum;
    }
};


// [ Time taken: 22 m 20 s ]

// Approach (Two Pointer Technique)
// Sort the array
// Fix one number (nums[i])
// Use two pointers (left, right) to find the closest pair sum for that fixed number
// Compare current sum’s closeness to target → update closestSum if better
// Move pointers:
// If sum < target → left++ (need bigger sum)
// If sum > target → right-- (need smaller sum)
// If sum == target → exact match → return immediately

// TC - O(n)
// SC - O(1) 
