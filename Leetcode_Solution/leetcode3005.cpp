/*
Problem:
---------
We are given an array `nums` of positive integers.
We need to return the total frequencies of all elements that occur
with the maximum frequency in the array.

Example:
--------
nums = [1,2,2,3,1,4]
- freq(1) = 2
- freq(2) = 2
- freq(3) = 1
- freq(4) = 1

Maximum frequency = 2
Elements with that frequency = {1, 2}
Total frequency = 2 + 2 = 4   ✅ answer

-------------------------------------------------------------------------------
Approach 1: Beginner-Friendly (Two Pass Solution)
-------------------------------------------------------------------------------
1. Count frequency of each element (using unordered_map).
2. Find the maximum frequency value.
3. Sum the frequencies of all elements that match that maximum frequency.
4. Return the result.

Time Complexity: O(n)
Space Complexity: O(n)
This is very clear and easy to explain to juniors.

-------------------------------------------------------------------------------
Approach 2: Optimized (Single Pass Solution)
-------------------------------------------------------------------------------
- While counting, we also keep track of:
  * Current maximum frequency.
  * Running total of elements that match this frequency.

Logic:
- Every time we update the frequency of an element:
    - If this new frequency > maxFreq:
         → Update maxFreq
         → Reset total = that frequency
    - Else if this new frequency == maxFreq:
         → Add this frequency to total
- This way, no second pass is needed.

Time Complexity: O(n)
Space Complexity: O(n)
Fewer iterations, but logic is slightly trickier to explain.
Use this when you care about performance & conciseness.

-------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------------
// Approach 1: Clear Two-Pass
// ---------------------
class SolutionClear {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        // Step 3: Sum all frequencies equal to maxFreq
        int res = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                res += p.second;
            }
        }

        // Step 4: Return result
        return res;
    }
};

// ---------------------
// Approach 2: Optimized One-Pass
// ---------------------
class SolutionOptimized {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0, total = 0;

        for (int num : nums) {
            int f = ++freq[num];

            if (f > maxFreq) {
                // New maximum found → reset total
                maxFreq = f;
                total = f;
            } else if (f == maxFreq) {
                // Another element reached same maximum → add to total
                total += f;
            }
        }
        return total;
    }
};

/*
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
- Approach 1 is easier to understand → first find max, then sum.
- Approach 2 is more compact → updates max & total on the fly.
- Both are O(n) time and O(n) space.
- For learning: start with Approach 1.
- For production code (where performance matters): Approach 2 can be used.
-------------------------------------------------------------------------------
*/
