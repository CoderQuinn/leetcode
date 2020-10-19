//
//  36 Valid Sudoku.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/12.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool state[10];
        
        for(int i = 0; i < 9; i++) // 行
        {
            memset(state, 0, sizeof state);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int t = board[i][j] - '0';
                    if(state[t]) return false;
                    state[t] = true;
                }
            }
        }
        
        for(int i = 0; i < 9; i++) // 列
        {
            memset(state, 0, sizeof state);
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    int t = board[j][i] - '0';
                    if(state[t]) return false;
                    state[t] = true;
                }
            }
        }
        
        for(int i = 0; i < 9; i += 3) // 扫描小方格
        {
            for(int j = 0; j < 9; j += 3)
            {
                memset(state, 0, sizeof state);
                for(int x = 0; x < 3; x++)
                {
                    for(int y = 0; y < 3; y++)
                    {
                        if(board[i + x][j + y] != '.')
                        {
                            int t = board[i + x][j + y] - '0';
                            if(state[t]) return false;
                            state[t] = true;
                        }
                    }
                }
            }
        }
        
        return true;
        
    }
};
