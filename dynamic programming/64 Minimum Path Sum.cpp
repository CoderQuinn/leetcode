//
//  64 Minimum Path Sum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> f(n, vector<int>(m, INT_MAX));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!i && !j) f[0][0] = grid[0][0];
                else
                {
                    if(i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    if(j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        }
        
        return f[n - 1][m - 1];
    }
};
