//
//  171 Excel Sheet Column Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/16.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans = (s[i] - 'A' + 1) + 26 * ans;
        }
        return ans;
    }
};
