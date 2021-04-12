//
//  289 Game of Life.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/8.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int live = 0, val = 0;
                for(int x = max(0, i - 1); x <= min(i + 1, n - 1); x++)
                {
                    for(int y = max(0, j - 1); y <= min(j + 1, m - 1); y++)
                    {
                        if(x == i && y == j) continue;
                        if((board[x][y] & 1) == 1) live++;
                    }
                }
                if(board[i][j] & 1) {
                    if(live < 2) val = 0;
                    else if(live <= 3) val = 1;
                    else val = 0;
                }
                else {
                    if(live == 3) val = 1;
                }
                board[i][j] |= (val << 1);
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board[i][j] >>= 1;
    }
};
