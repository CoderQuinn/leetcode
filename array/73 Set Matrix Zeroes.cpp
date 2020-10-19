//
//  73 Set Matrix Zeroes.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/19.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        if(!n) return;
        auto m = matrix[0].size();
        
        int r0 = 1, c0 = 1;
        
        // 第一行
        for(int i = 0; i < m; i++)
        {
            if(!matrix[0][i])
            {
                r0 = 0;
                break;
            }
        }
        
        // 第一列
        for(int i = 0; i < n; i++)
        {
            if(!matrix[i][0])
            {
                c0 = 0;
                break;
            }
        }
        
        // 枚举其他行
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        
        // 枚举其他列
        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(!matrix[i][j])
                {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        
        // 修改其他行
        for(int i = 1; i < n; i++)
        {
            if(!matrix[i][0])
            {
                for(int j = 1; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // 修改其他列
        for(int j = 1; j < m; j++)
        {
            if(!matrix[0][j])
            {
                for(int i = 1; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // 第一行
        if(!r0)
            for(int i = 0; i < m; i++)
            {
                matrix[0][i] = 0;
            }
        
        // 第一列
        if(!c0)
            for(int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        
    }
};
