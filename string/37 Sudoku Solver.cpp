//
//  37 Sudoku Solver.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/25.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    
    bool rows[9][9];
    bool cols[9][9];
    bool cells[3][3][9];
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(cells, 0, sizeof(cells));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int tmp = board[i][j] - '1';
                    rows[i][tmp] = true;
                    cols[j][tmp] = true;
                    cells[i / 3][j / 3][tmp] = true;
                }
            }
        }
        
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y)
    {
        if(y == 9){
            y = 0;
            x ++;
        }
        
        if (x == 9) return true;
        
        if (board[x][y] != '.') {
            return dfs(board, x, y + 1);
        }
        
        for (int i = 0; i < 9; i++) {
            if (!rows[x][i] && !cols[y][i] && !cells[x / 3][y / 3][i]) {
                int tmp = i + '1';
                board[x][y] = tmp;
                rows[x][i] = cols[y][i] = cells[x / 3][y / 3][i] = true;
                if (dfs(board, x, y + 1)) {
                    return true;
                }
                board[x][y] = '.';
                rows[x][i] = cols[y][i] = cells[x / 3][y / 3][i] = false;
            }
        }
        
        return false;
    }
};
