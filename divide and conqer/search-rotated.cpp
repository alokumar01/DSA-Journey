#include<iostream>
using namespace std;

int searchRotated(int arr[], int si, int ei,  int target) {
    if (si > ei) return -1;
    int mid = si + (ei - si) / 2;

    if (arr[mid] == target) return mid;

    if (arr[si] <= arr[mid]) { // line1
        if (arr[si] <= target && target < arr[mid]) { 
            return searchRotated(arr, si, mid-1, target); //left
        } else {
            return searchRotated(arr, mid+1, ei, target); //right
        }
        
    } else { //line2
        if (arr[mid] < target && target <= arr[ei]) {
            return searchRotated(arr, mid+1, ei, target); //right
        } else {
            return searchRotated(arr, si, mid-1, target); //left
        }
    }
}


int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2 };
    int n = 7;
    cout << "Idx: " << searchRotated(arr, 0, n-1, 0);
}