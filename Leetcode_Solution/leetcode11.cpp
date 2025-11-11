class Solution {
public:
    int maxArea(vector<int>& height) {
        // Greedy + Two Pointer
        int left = 0, right = height.size()-1;
        int max_area = 0;

        while(left < right) {
            //width btw two lines
            int width = right - left;
            //taking height or limiting with who have shorter height
            int curr_height = min(height[left], height[right]);
            //calcualte area
            int area = width * curr_height;
            //update max when possible
            max_area = max(max_area, area);

            if (height[left] < height[right])
                left+=1;
            else
                right -= 1;
        }

        return max_area;
    }
};


// [ Time taken: 32 m 30 s ] REVISION
// Approach: Two Pointer + Greedy

// Start with two pointers:
// left = 0, right = n - 1

// area = (right - left) * min(height[left], height[right])
// Update max area.
// Move the pointer pointing to the shorter height, because:
// The smaller line limits the area.
// Moving the taller one can only reduce width without increasing height.
// Repeat until left >= right.

// TC - O(N), O(1)