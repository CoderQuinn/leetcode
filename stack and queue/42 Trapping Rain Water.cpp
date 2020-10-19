//
//  42 Trapping Rain Water.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<int> st;
        int res = 0;
        
        for (int i = 0; i < height.size(); i++) {
            int last = 0;
            while (!st.empty() && height[st.top()] <= height[i]) {
                res += (height[st.top()] - last) * (i - st.top() - 1);
                last = height[st.top()];
                st.pop();
            }
            
            if(!st.empty())
                res += (height[i] - last) * (i - st.top() - 1);
            st.push(i);
        }
        
        return res;
    }
};
