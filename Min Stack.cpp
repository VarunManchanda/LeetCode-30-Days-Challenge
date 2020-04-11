/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack1;
    stack<int> stackMin;
    MinStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        if(stackMin.empty()){
            stackMin.push(x);
        }
        else
        {
            if(x <= stackMin.top())
            {
                stackMin.push(x);
            }
        }
    }
    
    void pop() {
        int x = stack1.top();
        if(x==stackMin.top())
        {
            stackMin.pop();
        }
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        if(!stackMin.empty())
        {
            return stackMin.top();
        }
        return stackMin.top();
    }
};
