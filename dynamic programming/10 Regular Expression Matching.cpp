//
//  10 Regular Expression Matching.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/8.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        auto n = s.length();
        auto m = p.length();
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j + 1 <= m && p[j + 1]) continue;
                if (p[j] != '*') {
                    if (i > 0)
                        f[i][j] = f[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                } else {
                    f[i][j] = f[i][j - 2];
                    if (i > 0)
                        f[i][j] = f[i][j] || (f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        
        return f[n][m];
        
    }
};
