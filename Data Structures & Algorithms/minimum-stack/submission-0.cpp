class MinStack {
private:
    stack<int> minStack;
    stack<int> mainStack;
public:
    MinStack() {}
    
    void push(int val) {
        mainStack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
