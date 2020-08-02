//
//  ReverseString.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace::std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse_string_core(s, 0, (int)s.size() - 1);
    }
    
    void reverse_string_core(vector<char>& s, int letf, int right) {
        if (letf > right) return;
        char ch = s[letf];
        s[letf] = s[right];
        s[right] = ch;
        
        reverse_string_core(s, letf + 1, right - 1);
    }
};
