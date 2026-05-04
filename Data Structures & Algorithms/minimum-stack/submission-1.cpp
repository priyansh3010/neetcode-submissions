class MinStack {
    vector<int> mainStack;
    int stackIndex;
    vector<int> minStack;
public:
    MinStack() {
        stackIndex = -1;
    }
    
    void push(int val) {
        mainStack.push_back(val);
        minStack.push_back(stackIndex == -1 ? val : min(val, minStack[stackIndex]));
        stackIndex++;
    }
    
    void pop() {
        mainStack.pop_back();
        minStack.pop_back();
        stackIndex--;
    }
    
    int top() {
        return mainStack[stackIndex];
    }
    
    int getMin() {
        return minStack[stackIndex];
    }
};
