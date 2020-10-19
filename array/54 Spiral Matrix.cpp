//
//  54.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/4.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        auto n = matrix.size();
        if(!n) return res;
        auto m = matrix[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m));
        int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; i++) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            
            int a = x + step[d][0];
            int b = y + step[d][1];
            if (a < 0 || a >= n || b < 0 || b >= m || visited[a][b]) {
                d = (d + 1) % 4;
                a = x + step[d][0];
                b = y + step[d][1];
            }
            x = a;
            y = b;
        }
        return res;
    }
};
