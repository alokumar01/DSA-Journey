#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void slidingWindowMax(vector<int> arr, int K) {
    priority_queue<pair<int, int>> pq;

    for(int i=0; i<K; i++) {
        pq.push(make_pair(arr[i], i));
    }

    cout << "output : " << pq.top().first << " ";
    for(int i=K; i<arr.size(); i++) {
        while(!pq.empty() && pq.top().second <= (i-K)){
            pq.pop();    
        }
        
        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " " ;
    }
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    int K = 3;
    slidingWindowMax(arr, K);

    return 0;
}