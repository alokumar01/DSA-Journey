class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // this is valid answer
        int left = 0, right = arr.size() - 1;

        while( left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1] ) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};


/// below is also acceptable on leetcode

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // binary search // tc -> logn, sc -> O(1)
        int left = 0, right = arr.size() - 1;

        while( left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            if (arr[mid] < arr[mid - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};