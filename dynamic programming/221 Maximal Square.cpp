//
//  221 Maximal Square.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if(matrix.empty() || matrix[0].empty())
            return res;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(matrix[i - 1][j - 1] == '1') {
                    f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
                    res = max(res, f[i][j] * f[i][j]);
                }
            }
        }

        return res;

    }
};
