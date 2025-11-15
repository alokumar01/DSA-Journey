class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        res.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            while (!pq.empty() && pq.top().second <= (i - k)) {
                pq.pop();
            }
            pq.push(make_pair(nums[i], i));
            res.push_back(pq.top().first);
        }

        return res;
    }
};

[ Time taken: 15 m 35 s ] REVISION
TC -O(n log k)
SC - O(K)

We can use deque to make this optimal