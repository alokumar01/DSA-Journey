// Question 1 :
// Rat in a Maze
// You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the
// maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a
// square matrix of order N * N where the cells with value 0 represent the maze’s blocked
// locations while value 1 is the open/available path that the rat can take to reach its destination.
// The rat's destination is at (N - 1, N - 1).
// Your task is to find all the possible paths that the rat can take to reach from source to
// destination in the maze.
// The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down)
// i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).
// (This problem is similar to Grid ways.)




#include <iostream>
#include <vector>
using namespace std;

int ratInMaze(int r, int c, int n, int m, string res, int maze[4][4], bool visited[][4]) {
    if (r == n - 1 && c == m - 1) {
        cout << res << "\n";
        return 1;
    }

    if(visited[r][c]) return 0;
    if (r<0 || c < 0) return 0;
    if (r >= n || c >= m) return 0;
    if (maze[r][c] == 0) return 0;

    visited[r][c] = true;

    //find ways for down
    int down = ratInMaze(r+1, c, n, m, res + "D", maze, visited);
    //find ways for left
    int left = ratInMaze(r, c-1, n, m, res+"L", maze, visited); 
    // ways for right
    int right =  ratInMaze(r, c+1, n, m, res + "R", maze, visited);
    // find ways for up
    int up = ratInMaze(r-1, c, n, m, res+ "U", maze, visited);

    visited[r][c] = false;

    return right + down + up + left;
}

int main() {
    int maze[4][4] = { { 1, 1, 1, 1 },
                        { 1, 1, 0, 1 },
                        { 1, 1, 0, 1 },
                        { 0, 1, 1, 1 } };
    string res;
    int n = 4;
    int m = 4;
    bool visited[4][4] = {false};

    cout << ratInMaze(0, 0, n, m, res, maze, visited);

    return 0;
}



///  gfg rat in maze
class Solution {
public:
    // Helper recursive function to explore paths
    void ratWay(int r, int c, int n, vector<vector<int>>& maze, bool visited[10][10], 
                string res, vector<string>& ans) {

        if (r == n - 1 && c == n - 1) {
            ans.push_back(res);
            return;
        }
        if (r < 0 || c < 0 || r >= n || c >= n) return;
        if (maze[r][c] == 0) return;
        if (visited[r][c]) return;


        visited[r][c] = true;

        ratWay(r + 1, c, n, maze, visited, res + "D", ans); // Dow
        
        ratWay(r, c - 1, n, maze, visited, res + "L", ans); // Left
        
        ratWay(r, c + 1, n, maze, visited, res + "R", ans); // Right
        
        ratWay(r - 1, c, n, maze, visited, res + "U", ans); // Up

        visited[r][c] = false;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string res = "";
        int n = maze.size();
        bool visited[10][10] = {false}; 

        if (maze[0][0] == 1) {
            ratWay(0, 0, n, maze, visited, res, ans);
        }

        return ans;
    }
};


// word search leetcode 79
class Solution {
public:

    bool dfs(vector<vector<char>>& board, vector<vector<bool>> &vis, int row, int col, int k, string word) {
        int n = board.size(); //row
        int m = board[0].size(); //col
        
        if (k == word.size()) return true;
        if (row < 0 || col < 0 || row >= n || col >= m) return false;
        if (vis[row][col]) return false;
        if (board[row][col] != word[k]) return false;

        // you can also use inplace marking visited

        vis[row][col] = true;
        bool found = dfs(board, vis, row+1, col, k+1, word) ||
                    dfs(board, vis, row-1, col, k+1, word) ||
                    dfs(board, vis, row, col+1, k+1, word) ||
                    dfs(board, vis, row, col-1, k+1, word);
        
        vis[row][col] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); //row
        int m = board[0].size(); //col
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int k = word.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, vis, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

