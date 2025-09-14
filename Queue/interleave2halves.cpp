#include <iostream>
using namespace std;
#include<queue>

void interleave(queue<int>& org) {
    int n = org.size();
    queue<int>first;

    for(int i=0; i<n/2; i++) {
        first.push(org.front());
        org.pop();
    }

    while(!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}


int main() {
    queue<int> q;
    for(int i=1; i<=10; i++) {
        q.push(i);
    }

    interleave(q);

    for(int i = 1; i<=10; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}