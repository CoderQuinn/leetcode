//
//  84 Largest Rectangle in Histogram.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            
            stk.push(i);
        }
        
        while(!stk.empty())
            stk.pop();
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty()) right[i] = n;
            else right[i] = stk.top();
            
            stk.push(i);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        
        return res;
    }
};
