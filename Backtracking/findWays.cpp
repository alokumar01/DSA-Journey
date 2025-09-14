
#include<iostream>
#include<vector>
using namespace std;

// int gridWays(int r, int c, int n, int m, string res) {
//     if (r == n - 1 && c == m - 1) {
//         cout << res << "\n";
//         return 1;
//     }

//     if (r >= n || c >= m) {
//         return 0;
//     }

//     //right
//     int val1 = gridWays(r, c+1, n, m, res + "R");
//     //down
//     int val2 = gridWays(r+1, c, n, m, res + "D");

//     return val1 + val2;
// }


int gridWays(int r, int c, int n, int m, string res) {
    if (r == n - 1 && c == m - 1) {
        cout << res << "\n";
        return 1;
    }

    if (r >= n || c >= m) return 0;

    // find ways for right
    int val1 = gridWays(r,c+1, n, m, res + "R");
    //find ways for down dir
    int val2 = gridWays(r+1, c, n, m, res + "D");

    return val1 + val2;
}

int main() {
    int n = 3;
    int m = 2;
    string res;
    cout << gridWays(0, 0, n, m, res);
}


