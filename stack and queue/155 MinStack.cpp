//
//  MinStack.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace::std;

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> min_stack;
    stack<int> data_stack;
    MinStack()
    {
        
    }

    void push(int x)
    {
        data_stack.push(x);
        int val = x;
        if (!min_stack.empty() && val > min_stack.top())
        {
            val = min_stack.top();
        }
        min_stack.push(val);
    }

    void pop()
    {
        data_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return data_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
