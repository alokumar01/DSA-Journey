#include <iostream>
using namespace std;
#include <queue>

class Stack {
    queue<int> q1;
    queue<int> q2;

public:
    void push(int data){
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        q1.pop();
    }

    int top() {
        return q1.front();
    }


    bool empty() {
        return q1.empty();
    }
};



int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // Should print 30

    s.pop();
    cout << "Top after pop: " << s.top() << endl; // Should print 20

    s.push(40);
    cout << "Top after pushing 40: " << s.top() << endl; // Should print 40

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}