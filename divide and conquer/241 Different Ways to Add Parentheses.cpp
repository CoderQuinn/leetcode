//
//  241 Different Ways to Add Parentheses.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/30.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> expr;
    vector<int> diffWaysToCompute(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int j = i, x = 0;
                while (j < s.size() && isdigit(s[j]))
                {
                    x = s[j++] - '0' + x * 10;
                }
                i = j - 1;
                expr.push_back(to_string(x));
            }
            else
            {
                expr.push_back(s.substr(i, 1));
            }
        }
        
        return dfs(0, expr.size() - 1);
    }
    
    vector<int> dfs(int l, int r)
    {
        if (l == r)
            return {stoi(expr[l])};
        vector<int> res;
        
        for (int i = l + 1; i < r; i += 2)
        {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto x : left)
                for (auto y : right)
                {
                    int z;
                    if (expr[i] == "+")
                        z = x + y;
                    else if (expr[i] == "-")
                        z = x - y;
                    else
                        z = x * y;
                    res.push_back(z);
                }
        }
        
        return res;
    }
};
