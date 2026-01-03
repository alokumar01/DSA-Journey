class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combination;
    // backtracking se solve kiya REVISION 

    void backtrack(vector<int>& candidates, int target, int idx) {
        // base case
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return ans;
    }
};