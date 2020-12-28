//
//  216 Combination Sum III.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(1, k, n);
        return ans;
    }

    void dfs(int start, int k, int n)
    {
        if (n == 0)
        {
            if (k == 0)
                ans.push_back(path);
        }
        else if (k > 0)
        {
            for (int i = start; i <= 9; i++)
            {
                if (i <= n)
                {
                    path.push_back(i);
                    dfs(i + 1, k - 1, n - i);
                    path.pop_back();
                }
            }
        }
    }
};
