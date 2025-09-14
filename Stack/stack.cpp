#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack {
    vector<int> vec;
public:

    void push(int val) {
        vec.push_back(val);
    }

    void pop() {
        if (vec.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    int top() {
        if (vec.empty()) {
            cout << "Stack is empty\n";
            return -1; // or throw an exception if you prefer
        }
        return vec.back();
    }

    bool isEmpty(){
        return vec.empty();
    }

    // Push an element at the bottom of this stack (recursive)
    void pushAtBottom(int x) {
        if (isEmpty()) {
            push(x);
            return;
        }

        int temp = top();
        pop();
        pushAtBottom(x);
        push(temp);
    }

    void stockSpanProblem(vector<int>&stock, vector<int>&span) {
        stack<int>s;
        s.push(0);
        span[0] = 1;

        for(int i=1; i<stock.size(); i++) {
            int currPrice = stock[i];
            while(!s.empty() && currPrice >= stock[s.top()]) {
                s.pop();
            }

            if (s.empty()) {
                span[i] = i+1;
            }else {
                int prevHigh = s.top();
                span[i] = i-prevHigh;
            }

            s.push(i);
        }

        for(int i=0;i<span.size(); i++) {
            cout << span[i] << " ";
        }
        cout << endl;

    }   

    void nextGreater(vector<int>&arr, vector<int>&ans) {
        stack<int> s;
        int idx = arr.size()-1;
        ans[idx] = -1;
        s.push(arr[idx]);

        for (idx = idx-1; idx>=0; idx--) {
            int curr = arr[idx];

            while(!s.empty() && curr >= s.top()) {
                s.pop();
            }

            if (s.empty()) {
                ans[idx] = -1;
            } else {
                ans[idx] = s.top();
            }

            s.push(curr);
        }


        for(int num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack ll;
    // vector<int>stock = {100, 80, 60,70,60, 85, 100};
    // vector<int>span = {0, 0, 0, 0, 0, 0, 0};
    // ll.stockSpanProblem(stock, span);

    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = {0, 0, 0, 0};
    ll.nextGreater(arr, ans) ;


    return 0;
}
