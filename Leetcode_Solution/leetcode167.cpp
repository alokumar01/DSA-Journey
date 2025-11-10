class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int currSum = numbers[left] + numbers[right];

            if (currSum > target) {
                right--;
            } else if (currSum < target) {
                left++;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {};
    }
};

//[ Time taken: 18 m 38 s ] REVISION 
// Two pointer uses array is sorted then I performed binary search.

// TC -  O(n)
// SC - O(1) constant space 