#include <iostream>
using namespace std;
#include<vector>

// void print(int num) {
//     if (num == 0) {
//         return;
//     }

//     cout << num << " ";
//     print(num - 1);
// }

// int main() {
//     print(50);
//     return 0;
// }

// FIBONACCI NUMBER
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;    
    }
    return fibonacci(n-1) + fibonacci(n - 2);
}

int main() {
    cout << fibonacci(6);
    return 0;
}



// CHECK ARRAY IS SORTED OR NOT USING RECURSIN
// bool isSorted(int arr[], int n, int i) {
//     if (i == n - 1) return true;
//     if (arr[i] > arr[i+1]) return false;
//     return isSorted(arr, n, i+1);
// }

// int main() {
//     int arr[5] = {1, 2,3,4,5};
//     int i = 0, n = 5;
//     cout << isSorted(arr, n, i);
// }


// first occurrence
// int firstOccur(vector<int>arr, int i, int target) {
//     if (i == arr.size()) {
//         return -1;
//     }

//     if (arr[i] == target) {
//         return i;
//     }

//     return firstOccur(arr, i+1, target);
// }

// int lastOccur(vector<int>arr, int target, int i) {
//     if (i == arr.size()) {
//         return -1;
//     }

//     int idxFound =  lastOccur(arr, target, i+1);
//     if (idxFound ==  -1 && arr[i] == target) {
//         return i;
//     }


//     return idxFound;
// }

// void print(int n) {
//     if (n == 0) return;

//     cout << n << " ";
//     print(n - 1);
// }

// int main() {
//     vector<int> arr = {1,2,8,3,4,5};
//     // cout << firstOccur(arr, 0, 4);
//     // cout << lastOccur(arr, 3, 0);

//     //priting all number from N to 1;
    
//     // print(50);

//     return 0;
// }