//
//  240 Search a 2D Matrix II.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/30.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0)
        {
            int x = matrix[i][j];
            if(x == target) return true;
            else if(x > target) j--;
            else i++;
        }
        return false;
    }
};
