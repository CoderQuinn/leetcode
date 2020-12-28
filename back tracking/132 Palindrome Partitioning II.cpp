//
//  132 Palindrome Partitioning II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/11/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        s = ' ' + s;
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        vector<int> f(n + 1, 1e9);
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                if (i == j) {
                    g[i][j] = true;
                }
                else if (s[i] == s[j])
                {
                    if(i + 1 > j - 1 || g[i + 1][j - 1])
                        g[i][j] = true;
                }
            }
        }
        
        f[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i ++) {
                if (g[i][j]) {
                    f[j] = min(f[j], f[i - 1] + 1);
                }
            }
        }
        
        return f[n] - 1;
    }
};
