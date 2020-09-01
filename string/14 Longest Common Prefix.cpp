//
//  14 Longest Common Prefix.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int i = 0;
        int length = strs[0].length();
        for (; i < length; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size()  || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0].substr(0, i);
    }
};
