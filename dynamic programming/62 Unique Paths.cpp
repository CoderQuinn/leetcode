//
//  62 Unique Paths.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0) f[i][j] = 1;
                else
                {
                    if(i > 0) f[i][j] += f[i - 1][j];
                    if(j > 0) f[i][j] += f[i][j - 1];
                }
            }
        }
        
        return f[n - 1][m - 1];
    }
};
