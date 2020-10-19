//
//  59 Spiral Matrix II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int i = 1, x = 0, y = 0, d = 0; i <= n * n; i++)
        {
            res[x][y] = i;
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= n || res[a][b] > 0)
            {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a;
            y = b;
        }

        return res;
    }
};
