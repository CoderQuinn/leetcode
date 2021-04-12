//
//  74 Search a 2D Matrix.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/19.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[l / m][l % m] == target;
    }
};
