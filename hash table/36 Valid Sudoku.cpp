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
        
        unordered_map<int, unordered_map<int, int>> rows;
        unordered_map<int, unordered_map<int, int>> columns;
        unordered_map<int, unordered_map<int, int>> boxes;
        
        for (int i = 0; i < 9; ++i) {
            rows[i] = unordered_map<int, int>();
            columns[i] = unordered_map<int, int>();
            boxes[i] = unordered_map<int, int>();
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    int num = ch - '0';
                    int box_index = ( i / 3) * 3 + j / 3;
                    
                    unordered_map<int, int> &row_i_map = rows[i];
                    if (row_i_map.count(num) > 0) {
                        row_i_map[num] += 1;
                    } else {
                        row_i_map[num] = 1;
                    }
                    
                    unordered_map<int, int> &column_j_map = columns[j];
                    if (column_j_map.count(num) > 0) {
                        column_j_map[num] += 1;
                    } else {
                        column_j_map[num] = 1;
                    }
                    
                    unordered_map<int, int> &box_index_map = boxes[box_index];
                    if (box_index_map[num] > 0) {
                        box_index_map[num] += 1;
                    } else {
                        box_index_map[num] = 1;
                    }
                    
                    
                    if (row_i_map[num] > 1 || column_j_map[num] > 1 || box_index_map[num] > 1) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int rows[9][10] = {0};
        int columns[9][10] = {0};
        int boxes[9][10] = {0};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    int num = ch - '0';
                    int box_index = ( i / 3) * 3 + j / 3;
                    
                    if (rows[i][num] != 0 || columns[j][num] != 0 || boxes[box_index][num] != 0) {
                        return false;
                    }
                    
                    rows[i][num] += 1;
                    columns[j][num] += 1;
                    boxes[box_index][num] += 1;
                }
            }
        }
        
        return true;
    }
};
