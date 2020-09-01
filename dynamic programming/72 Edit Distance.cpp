//
//  72 Edit Distance.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        word1.insert(word1.begin(), ' ');
        word2.insert(word2.begin(), ' ');
        
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++)
            f[i][0] = i; // delete
        
        for (int i = 1; i <= m; i++)
            f[0][i] = i; // insert
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                int c = word1[i] != word2[j];
                f[i][j] = min(f[i - 1][j - 1] + c, f[i][j]);
            }
        }
        
        return f[n][m];
    }
};
