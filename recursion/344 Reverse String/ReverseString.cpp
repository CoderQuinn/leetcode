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
        if (s.empty() || s.size() == 1) return;
        reverse_string_core(s, 0, s.size()-1);
    }
    
    void reverse_string_core(vector<char>& s, unsigned long letf, unsigned long right) {
        if (letf >= right) return;
        char temp_c = s[right];
        s[right] = s[letf];
        s[letf] = temp_c;

        letf++;
        right--;
        reverse_string_core(s, letf, right);
    }
};
