//
//  120 Triangle.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        const int INF = 0x3f3f3f3f;
        int n = triangle.size();
        int m = triangle.back().size();
        
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INF));
        
        f[1][1] = triangle[0][0];
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j <= i; j++) {
                f[i][j] = min(f[i-1][j], f[i-1][j-1]) + triangle[i - 1][j - 1];
            }
        }
        
        int value = INF;
        for (int i = 1; i <= m; i++) {
            value = min(value, f[n][i]);
        }
        return value;
    }
};
