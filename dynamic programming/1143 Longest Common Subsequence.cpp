//
//  1143 Longest Common Subsequence.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        
        text1.insert(text1.begin(), ' ');
        text2.insert(text2.begin(), ' ');
        
        vector<vector<int>> f(l1 + 1, vector<int>(l2 + 1, 0));
        
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i] == text2[j]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                }
            }
        }
        
        return f[l1][l2];
    }
};
