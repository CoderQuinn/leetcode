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
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if(i == 1 || j == 1) f[i][j] = 1;
                else
                {
                    f[i][j] += f[i][j - 1] + f[i - 1][j];
                }
            }
        }
        
        return f[m][n];
    }
};
