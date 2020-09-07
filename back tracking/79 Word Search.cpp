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

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, 0, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool dfs(vector<vector<char>> &board, int u, int x, int y, string &word)
    {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1) return true;
        
        char tmp = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size() && board[next_x][next_y] != '.') {
                if(dfs(board, u + 1, next_x, next_y, word))
                    return true;;
            }
        }
        board[x][y] = tmp;
        
        return false;
    }
    
};
