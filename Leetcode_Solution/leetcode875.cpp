class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //binary search
        int left = 1; // min she can eat bananas per hour 
        int right = *max_element(piles.begin(), piles.end()); // max she can eat

        while( left < right) {
            int mid = (left + right) >> 1;

            int totalHrs = 0;
            for(int pile : piles) {
                totalHrs += (pile + mid - 1) / mid;
            }

            if (totalHrs <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};


//notes

// [ Time taken: 34 m 6 s ]
// O(n(log(max(pile)));
// Final Explanation Summary (Memory Version)
// We want smallest speed Koko needs.
// Range = [1 … max pile].
// For a trial speed mid, compute hours using ceiling.
// If hours ≤ h → try slower (right = mid)
// If hours > h → speed too slow (left = mid + 1)
// Return left.