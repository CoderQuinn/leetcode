//
//  44 Wildcard Matching.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/30.
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
        s = ' ' + s;
        p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {
                    f[i][j] = f[i][j - 1] ||  (i > 0 && f[i - 1][j]);
                } else {
                    f[i][j] = (s[i] == p[j] || p[j] == '?') && (i > 0 && f[i - 1][j - 1]);
                }
            }
        }
        
        return f[n][m];
    }
};
