//
//  96 Unique Binary Search Trees.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                f[i] += f[j - 1] * f[i - j];
            }
        }
        return f[n];
    }
};
