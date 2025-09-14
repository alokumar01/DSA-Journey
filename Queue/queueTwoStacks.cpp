#include <iostream>
using namespace std;
#include <stack>
class Queue {
    stack<int> s1;
    stack<int> s2;
public:

    bool empty() {
        return s1.empty();
    }


    void push(int data) {
        // s1->s2 first send all elements of s1 into s2 
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        // s2->s1 sending back all elemtns into s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    int front() {
        return s1.top();
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();    
    }
    return 0;
}