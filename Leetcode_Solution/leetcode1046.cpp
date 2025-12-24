class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int res = 0;

        for(int stone : stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {
            int y = pq.top(); //1st largest
            pq.pop(); 

            int x = pq.top(); // 2nd largest
            pq.pop(); 

            if (x != y) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? res : pq.top();
    }
};