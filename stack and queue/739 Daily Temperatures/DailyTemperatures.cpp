//
//  DailyTemperatures.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <vector>
using namespace::std;

// 暴力枚举


// 栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> result_vector(T.size(), 0);
        std::stack<int> stack;
        
        for (int i = 0; i < T.size(); i++) {
            while (!stack.empty()) {
                int j = stack.top();
                if (T[j] < T[i]) {
                    result_vector[j] = i - j;
                    stack.pop();
                } else {
                    break;
                }
            }
            
            stack.push(i);
        }
        
        return result_vector;
    }
};
