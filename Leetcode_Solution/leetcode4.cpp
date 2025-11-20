class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // tc - O(n + m), sc - O(1)
        int n = nums1.size(), m = nums2.size();
        int totalSize = n + m;

        int leftMedian = (totalSize - 1) / 2;
        int rightMedian = totalSize / 2;

        // two pointer technique
        int i = 0, j = 0, count = -1;
        int leftValue = 0, rightValue = 0, currentValue = 0;

        while (i < n || j < m) {
            if (j == m || (i < n && nums1[i] <= nums2[j])) {
                currentValue = nums1[i];
                i++;
            } else {
                currentValue = nums2[j];
                j++;
            }

            count++;

            if (count == leftMedian)
                leftValue = currentValue;
            if (count == rightMedian)
                rightValue = currentValue;
        }
        // if totalSize is odd return rightValue else (l + r) / 2.0
        return (totalSize % 2 == 1) ? rightValue : (leftValue + rightValue) / 2.0;
    }
};

/// WAY TO SOLVE THIS
// [ Time taken: 30 m 12 s ]
// Compute:

// leftMedian = (totalSize - 1) / 2
// rightMedian = totalSize / 2

// Initialize:
// i = 0, j = 0 (two pointers)
// count = -1
// leftValue, rightValue

// While either array has elements:
// If j == m OR (i < n AND nums1[i] <= nums2[j]):
// → pick nums1[i], i++
// Else:
// → pick nums2[j], j++
// count++

// If count == leftMedian → save leftValue
// If count == rightMedian → save rightValue

// After loop:

// If total size is odd → return rightValue
// Else → return (leftValue + rightValue) / 2.0

// ⭐ Why this works
// You simulate the merge of two sorted arrays and stop once you reach the median positions — no need to merge fully, no extra space.
// ⭐ Time & Space Complexity

// Time: O(m + n) — each pointer moves through its array once
// Space: O(1) — only constant variables used

// ⭐ Why not binary search here?
// Use binary search partition (O(log(min(m, n)))) only when:
// The interview requires optimal time
// Arrays are extremely large
// You want the mathematically optimal solution
// Binary search is faster but much more complex.
// Two-pointer is simpler and perfectly valid unless optimal time is required.