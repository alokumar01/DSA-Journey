#include<iostream>
using namespace std;


int parititon(int arr[], int si, int ei) {
    int i = si - 1, pivot = arr[ei];

    for(int j = si; j<ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void quickSort(int arr[], int si, int ei) {
    if (si>=ei) return;
    int privotIdx = parititon(arr, si, ei);

    quickSort(arr, si, privotIdx-1); //left;
    quickSort(arr, privotIdx+1, ei); // right

}

void printArr(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
}



int main() {
    int arr[7] = {3,2, 5,6, 7,1, 4};
    int n = 7;
    quickSort(arr, 0, n - 1);
    printArr(arr, n);
}