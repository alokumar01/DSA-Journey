class Solution {
public:
    // Time complexity -> O(n!)
    // space complexity -> O(n)
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int idx) {
        if (nums.size() == idx) {
            ans.push_back(nums); // base case
            return;
        }

        for (int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]); 
            backtrack(nums, idx+1);
            swap(nums[idx], nums[i]); // backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};