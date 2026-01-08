class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(vector<int>& nums, int idx) {
        //bc
        ans.push_back(subset);

        for (int i=idx; i<nums.size(); i++) {
            //skip
            if (i > idx && nums[i] == nums[i-1]) continue; // require sorting 

            subset.push_back(nums[i]);
            backtrack(nums, i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};