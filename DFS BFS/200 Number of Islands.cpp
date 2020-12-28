//
//  200 Number of Islands.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int cnt = 0;

        for(int i = 0; i < g.size(); i++) {
            for(int j = 0; j < g[0].size(); j++) {
                if(g[i][j] == '1') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(int x, int y) {
        g[x][y] = '0';

        for(int i = 0; i < 4; i++) {
            int a = dx[i] + x, b = dy[i] + y;
            if(a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] == '1') {
                dfs(a, b);
            }
        }
    }

};
