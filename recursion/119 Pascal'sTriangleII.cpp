//
//  Pascal'sTriangleII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

// iteration  O(n) 空间复杂度
class Solution
{
public:
    vector<int> getRow(int n)
    {
        vector<vector<int>> f(2, vector<int>(n + 1));
        for (int i = 0; i <= n; i++)
        {
            f[i & 1][0] = f[i & 1][i] = 1;
            for (int j = 1; j < i; j++)
            {
                f[i & 1][j] = f[i - 1 & 1][j - 1] + f[i - 1 & 1][j];
            }
        }
        return f[n & 1];
    }
};
