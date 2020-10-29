//
//  85 Maximal Rectangle.cpp
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(i > 0)
                        f[i][j] = 1 + f[i - 1][j];
                    else
                        f[i][j] = 1;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = max(res, largestRectangleArea(f[i]));
        }
        return res;
    }
};
