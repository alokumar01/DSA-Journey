#include <iostream>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

void countingsort(int *arr, int n) {

    int minVal = INT_MAX, maxVal = INT_MIN;
    int freq[100000] = {0};  

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }


    int j = 0;
    for(int i = minVal; i < maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i + minVal;
            freq[i]--;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[8] = {1, 2, 1, 3, 4, 5, 4, 6};
    int n = 8;

    countingsort(arr, n);

    return 0;
}
