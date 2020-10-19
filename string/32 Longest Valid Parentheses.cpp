//
//  32 Longest Valid Parentheses.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/25.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stack>
#include <string>
using namespace std;

// 括号合法前提：1. 左右括号数量相等 2. 任意前缀中左括号数量大于等于右括号的数量
// 以第一个不合法的右括号为界限来分段考虑
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        
        int res = 0;
        auto n = s.length();
        for(int i = 0, start = -1; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else {
                if(!st.empty())
                {
                    st.pop();
                    if(!st.empty())
                    {
                        res = max(res, i - (st.top() + 1) + 1);
                    }
                    else
                    {
                        res = max(res, i - (start + 1) + 1);
                    }
                }
                else
                {
                    start = i;
                }
            }
        }
        
        return res;
    }
};
