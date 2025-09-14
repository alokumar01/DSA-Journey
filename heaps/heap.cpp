#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Heap {
    vector<int> vec;
public:
    
    void push(int val) {
        vec.push_back(val); // step 1

        //fix heap
        int x = vec.size()-1;
        int parI = (x-1) / 2;
        while(parI >= 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int i) {
        if (i >= vec.size()) return;
    
        int l = 2*i+1;
        int r = 2*i+2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }

        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        if(maxIdx != i) {
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx);
        }
    }

    void pop() {
        // step 1
        swap(vec[0], vec[vec.size()-1]);

        // step 2
        vec.pop_back();

        // step 3
        heapify(0); // O(logn);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }


};

int main() {
    Heap heap;
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);
    
    while(!heap.empty()) {
        cout << "top: " << heap.top() << endl;
        heap.pop();
    }
    // cout << "top: " <<  heap.top() << endl;
    return 0;
}