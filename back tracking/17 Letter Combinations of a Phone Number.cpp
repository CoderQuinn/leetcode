//
//  17 Letter Combinations of a Phone Number.cpp
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
    string path;
    
    string phones[11] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        
        auto size = digits.length();
        path.resize(size, ' ');
        dfs(digits, 0);
        return res;
    }
    
    void dfs(string digits, int n)
    {
        if (n == digits.length()) {
            res.push_back(path);
            return;
        }
        
        for (auto c : phones[digits[n] - '0']) {
            path[n] = c;
            dfs(digits, n + 1);
        }
    }
};
