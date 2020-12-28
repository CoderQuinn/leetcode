//
//  130 Surrounded Regions.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution
{
public:
    int n, m;
    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        if (!n) return;
        m = board[0].size();

        // 第一行 最后一行
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[n - 1][j] == 'O')
                dfs(board, n - 1, j);
        }

        // 第一列 最后一列
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        board[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O')
            {
                dfs(board, a, b);
            }
        }
    }
};
