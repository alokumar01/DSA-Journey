// FROM GFG Knight Walk
#include <vector>
#include <queue>
#include <utility>  // for pair
using namespace std;

class Solution {
  public:
    bool isValid(int i, int j, int n, vector<vector<bool>>& vis) {
        return (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j]);
    }
    
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        int n = N;
        int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
        int x1 = KnightPos[0] - 1, y1 = KnightPos[1] - 1;
        
        if (tx == x1 && ty == y1) return 0;
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({x1, y1});
        vis[x1][y1] = true;
        
        int res = 0;
        int ax[8] = {2, 2, -2, -2, 1, -1, 1, -1};
        int ay[8] = {1, -1, 1, -1, 2, 2, -2, -2};
        
        while (!q.empty()) {
            int size = q.size();
            res++;
            while (size != 0) {
                auto p = q.front();
                q.pop();
                
                int xx = p.first;
                int yy = p.second;
                
                for (int i = 0; i < 8; i++) {
                    int nx = xx + ax[i];
                    int ny = yy + ay[i];
                    
                    if (nx == tx && ny == ty) return res;
                    
                    if (isValid(nx, ny, n, vis)) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                size--;
            }
        }
        
        return res;
    }
};
