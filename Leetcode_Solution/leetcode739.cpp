class Solution {
public: 
    // Monotonic Stack(decreasing)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int prevIndex = s.top();
                s.pop();
                res[prevIndex] = i - prevIndex;
            }
            s.push(i);
        }

        return res;
    }
};


// 📝 Daily Temperatures —Short Notes

// Use monotonic decreasing stack (store indices).

// While current temp > temp at stack top:

// Pop index → set result = currentIndex − poppedIndex.

// Push current index.

// Remaining stack indices → no warmer day → stay 0.

// Time: O(n) (each index pushed & popped once).