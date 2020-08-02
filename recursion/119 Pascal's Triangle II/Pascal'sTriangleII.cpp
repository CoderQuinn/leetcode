//
//  Pascal'sTriangleII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

// iteration 0(k*(k-1) / 2)空间
class Solution0 {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector <int> > result_vec;
        
        for (int i = 1; i <= rowIndex + 1; i++) {
            result_vec.push_back(vector<int>(i));
            for (int j = 1; j <= i; j++) {
                if (i == 1 || j == 1 || i == j) {
                    result_vec[i-1][j-1] = 1;
                } else {
                    result_vec[i-1][j-1] = result_vec[i-2][j-2] + result_vec[i-2][j-1];
                }
            }
        }
        
        return result_vec.back();
    }
};

// iteration  O(n) 空间复杂度
class Solution1 {
    vector<int> getRow(int rowIndex) {
        vector <int>  last_vec(rowIndex + 1);
        vector <int>  result_vec(rowIndex + 1);
        vector <int> *curr = &result_vec;
        vector <int> *prev = &last_vec;
        
        for (int i = 1; i <= rowIndex + 1; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1 || i == j) {
                    (*curr)[j - 1] = 1;
                } else {
                    (*curr)[j - 1] = (*prev)[j -2] + (*prev)[j - 1];
                }
            }
            
            vector<int> *tmp = curr;
            curr = prev;
            prev = tmp;
        }
        return *prev;
    }
};

// recursion
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        if (rowIndex == 0) {
            result[0] = 1;
            return result;
        }
        vector<int> prev_vec = getRow(rowIndex - 1);

        for (int j = 1; j <= rowIndex + 1; ++j) {
            if (j == 1 || j == rowIndex + 1) {
                result[j-1] = 1;
            } else {
                result[j-1] = prev_vec[j-2] + prev_vec[j-1];
            }
        }
        return result;
    }
};

// recursion
class Solution3 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        vector<int> last_result(rowIndex + 1);
        get_row_core(rowIndex, result, last_result);
        return result;
    }
    
    void get_row_core(int rowIndex, vector<int> &result_vec, vector<int> &last_vec) {
        if (rowIndex == 0) {
            result_vec[0] = 1;
            return;
        }
        get_row_core(rowIndex - 1, last_vec, result_vec);
        for (int j = 1; j <= rowIndex + 1; ++j) {
            if (j == 1 || j == rowIndex + 1) {
                result_vec[j-1] = 1;
            } else {
                result_vec[j-1] = last_vec[j-2] + last_vec[j-1];
            }
        }
    }
};
