//
//  63 Unique Paths II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(!n) return 0;
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> f(n, vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    if(!i && !j) f[0][0] = 1;
                    else
                    {
                        if(i) f[i][j] += f[i - 1][j];
                        if(j) f[i][j] += f[i][j - 1];
                    }
                }
            }
        }
        
        return f[n - 1][m - 1];
    }
};
