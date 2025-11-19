class Solution {
public:
    bool search(vector<int>& mat, int target) {
        int low = 0, high = mat.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (target == mat[mid])
                return true;
            else if (target > mat[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search two times but still less than optimal.
        // we can optimze this more by using only one binary search
        // TC - O(log(n × m)) SC -  O(1)
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n - 1;
        int row = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (target == matrix[mid][0]) {
                return true;
            }

            if (target > matrix[mid][0]) {
                row = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (row == -1)
            return false;
            
        return search(matrix[row], target);
    }
};