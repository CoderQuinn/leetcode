#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top_val = peek();
        pop_stack.pop();
        return top_val;
    }
    
    /** Get the front element. */
    int peek() {
        if (pop_stack.empty())
        {
            while (!push_stack.empty())
            {
                int val = push_stack.top();
                push_stack.pop();
                pop_stack.push(val);
            }
        }
        return pop_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
    }

    private:
    std::stack<int> push_stack;
    std::stack<int> pop_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
