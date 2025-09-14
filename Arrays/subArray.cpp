#include <iostream>
using namespace std;

// printing the subarray 

// void printSubarray(int *arr, int n) {
//     for (int start=0; start<n; start++) {
//         for(int end=start; end<n; end++) {
//             for(int i=start; i<=end;i++) {
//                 cout << arr[i];
//             }
//             cout << ", ";
//         }
//         cout << endl;
//     }
// }
// int main() {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int n = 5;

//     printSubarray(arr, n);

//     return 0;
// }


// MAX SUBARRAY SUM BRUTE FORCE TC- O(N3);
// void maxsubarraySum(int *arr, int n) {
//     int maxSum = INT_MIN;
//     for (int start=0; start<n; start++) {
//         for(int end=start; end<n; end++) {
//             int currSum = 0;
//             for(int i=start; i<=end;i++) {
//                 currSum += arr[i];
//             }
//             cout << currSum << ", ";
//             maxSum = max(maxSum, currSum);
//         }
//         cout << endl;
//     }
//     cout << "The maximum subarray sum = " << maxSum << endl;
// }


// MAX SUBARRAY SUM BRUTE FORCE (BUT SLIGHTLY OPTIMIZED) TC- O(N2);
void maxsubarraySum2(int *arr, int n) {
    int maxSum = INT_MIN;

    for (int start=0; start<n; start++) {
        int currSum = 0;
        for(int end=start; end<n; end++) {
            currSum += arr[end];
            // cout << currSum << ", ";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }

    cout << "The maximum subarray sum = " << maxSum << endl;
}


// MAX SUBARRAY SUM KADANE'S ALGORITHM TC- O(N);
void kadanesAlgorithm(int *arr, int n) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i = 0; i<n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0) currSum = 0;
    }

    cout << "Maximum subarray sum (Kadane's Algorithm) = " << maxSum << endl;
}
// int main() {
//     int arr[6] = {-2, -3, -6, -5, -4, -2};
//     int n = 6;
//     // maxsubarraySum2(arr, n);
//     kadanesAlgorithm(arr, n);
//     return 0;
// }




// BEST TIME TO BUY AND SELL STOCKS LEETCODE(121)

void maxProfit(int *prices, int n) {
     
}





int main() {
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int n = 6;
    // maxsubarraySum2(arr, n);
    maxProfit(prices, n);
    return 0;
}