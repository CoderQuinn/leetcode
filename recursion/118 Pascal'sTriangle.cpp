//
//  Pascal'sTriangle.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

// iteration
class Solution1 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector <int> > result_vec;
        
        for (int i = 1; i <= numRows; i++) {
            result_vec.push_back(vector<int>(i));
            for (int j = 1; j <= i; j++) {
                if (i == 1 || j == 1 || i == j) {
                    result_vec[i-1][j-1] = 1;
                } else {
                    result_vec[i-1][j-1] = result_vec[i-2][j-2] + result_vec[i-2][j-1];
                }
            }
        }
        
        return result_vec;
    }
};

// recursion
class Solution2 {
public:
    
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector <int> >();
        vector<vector<int>> result = generate(numRows - 1);
        result.push_back(vector<int> (numRows));
        for (int j = 1; j <= numRows; ++j) {
            if (j == 1 || numRows == 1 || j == numRows) {
                result[numRows-1][j-1] = 1;
            } else {
                result[numRows-1][j-1] = result[numRows-2][j-2] + result[numRows-2][j-1];
            }
        }
        return result;
    }
};
