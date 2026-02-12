#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// int main() {
//     // int n = 5; // number of rides planned
//     // int m = 2; //m rides ke b price lagega
//     // int a = 2; // ek ride ka 2rupya
//     // int b = 3; // price for m rides
//     // use of math fxn
//     int n, m, a, b;
//     cin >> n >> m >> a >> b;

//     int totalSum = 0;
//     while(n >= 1) {
//         if (n > m) {
//             totalSum += b;
//             n = n - m;
//         } else {
//             totalSum += n * a;
//             break;
//         }
//     }

//     cout << totalSum;
//     return 0;
// }


int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int minCost = 0;

    while (n > 0) {
        if (n >= m) {
            minCost += min(b, m * a);  
            n -= m;
        } else {
            minCost += min(b, n * a); 
            break;
        }
    }

    cout << minCost;
    return 0;
}
