//
//  22 Generate Parentheses.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/12.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
    
    void dfs(int n, int left_count, int right_count, string path) {
        if (left_count == n && right_count == n) {
            res.push_back(path);
            return;
        }
        
        if (left_count < n) {
            dfs(n, left_count + 1, right_count, path + '(');
        }
        
        if (right_count < n && left_count > right_count) {
            dfs(n, left_count, right_count + 1, path + ')');
        }
    }
};
