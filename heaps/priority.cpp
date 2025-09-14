#include <iostream>
using namespace std;
#include <queue>


int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // this is min heap, Ascending 

    pq.push(3);
    pq.push(10);
    pq.push(5);

    while(!pq.empty()) {
        cout << "top: " << pq.top() << endl;
        pq.pop();
    }
    
    return 0;
}