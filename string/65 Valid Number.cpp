//
//  65 Valid Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // 1. 处理前后的空格
        int i = 0, j = s.size() - 1;
        
        while (s[i] == ' ') i++;
        while (s[j] == ' ') j--;
        if (i > j) return false;
        
        if (s[i] == '+' || s[i] == '-') i++;
        s = s.substr(i, j - i + 1);
        
        if (s.empty()) {
            return false;
        }
        
        // .e1的情况
        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E')) {
            return false;
        }
        
        int dot_cnt = 0, e_cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                continue;
            } else if (s[i] == '.') {
                if(dot_cnt > 0 || e_cnt > 0) // e后不能有'.', '.'最多只能有一个
                    return false;
                dot_cnt++;
            } else if (s[i] == 'e' || s[i] == 'E'){
                if(i == 0 || i + 1 == s.size() || e_cnt > 0) // e前后不为数字，重复的e
                    return false;
                if (s[i + 1] == '+' || s[i + 1] == '-') { // e的符号后要有数
                    if (i + 2 == s.size())
                        return false;
                    i++;
                }
                e_cnt++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
