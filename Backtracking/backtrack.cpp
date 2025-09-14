#include <iostream>
using namespace std;


void printArr(int arr[], int n) {
    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// void backtrack(int* arr, int n, int i) {
//     if (i == n) {
//         printArr(arr, n);
//         return;
//     }
//     arr[i] = i+1;
//     backtrack(arr, n, i+1);
//     arr[i] -= 2;
// }

void backtracking(int* arr, int n, int i ) {
    if(i == n) {
        printArr(arr, n);
        return;
    }
    arr[i] = i+1;
    backtracking(arr, n, i+1);
    arr[i] += 3;
}

int main() {
    int arr[5] = {0};
    int n = 5;
    // backtrack(arr, n , 0);
    backtracking(arr, n, 0);
    printArr(arr, n);
    return 0;
}