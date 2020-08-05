//
//  ValidateStackSequences.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
using namespace::std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> stack;
        
        vector<int>::iterator popped_it = popped.begin();
        for (vector<int>::iterator it = pushed.begin(); it != pushed.end(); ++it) {
            stack.push(*it);
            while (!stack.empty() && popped_it != popped.end() && *popped_it == stack.top()) {
                popped_it++;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
