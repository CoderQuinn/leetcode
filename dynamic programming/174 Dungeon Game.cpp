//
//  174 Dungeon Game.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/20.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int INF = 1e9;
        auto n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> f(n, vector<int>(m, INF));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) {
                    f[i][j] = max(1, 1 - dungeon[i][j]);
                } else {
                    if(i < n - 1) {
                        f[i][j] = f[i + 1][j] - dungeon[i][j];
                    }
                    if(j < m - 1) {
                        f[i][j] = min(f[i][j], f[i][j + 1] - dungeon[i][j]);
                    }
                    f[i][j] = max(1, f[i][j]);
                }
            }
        }
        
        return f[0][0];
    }
};
