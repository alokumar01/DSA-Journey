class MinStack {
    stack<pair<int, int>> st; // value, currentMin 
public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currMin = min(val, st.top().second);
            st.push({val, currMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



 ////
// ⭐ MinStack – Short Notes
// Approach 1: One Stack (pair method)

// Store: {value, currentMin}
// currentMin = min(value, previousMin)

// ✔ O(1): push, pop, top, getMin
// ✔ Space: O(n)
// ✔ Cleanest & easiest — min always at st.top().second

// Approach 2: Two Stacks

// mainSt → values

// minSt → track minimums
// Push to minSt when val <= minSt.top()
// Pop from both when equal

// ✔ O(1) operations
// ✔ Space: O(n)

// Why pair/why two stacks?

// Pair → simpler, one stack, min always available

// Two stacks → classic approach, easy logic