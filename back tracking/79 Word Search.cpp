//
//  79 Word Search.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/5.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<char>> g;
    string w;

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            g = board;
            w = word;
            for (int j = 0; j < g[0].size(); j++)
            {
                if (dfs(0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int u, int x, int y)
    {
        if (g[x][y] != w[u])
            return false;
        if (u == w.size() - 1)
            return true;

        char t = g[x][y];
        g[x][y] = '.';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= g.size() || b < 0 || b >= g[0].size() || g[a][b] == '.')
                continue;
            if (dfs(u + 1, a, b))
                return true;
        }

        g[x][y] = t;
        return false;
    }
};
