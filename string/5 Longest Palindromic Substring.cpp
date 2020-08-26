//
//  5 Longest Palindromic Substring.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string answer;
        auto length = s.length();
        for (int i = 0; i < length; ++i) {
            // "aba"
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < length && s[l] == s[r]) {
                l--;
                r++;
            }
            if (answer.length() < r - l - 1) {
                answer = s.substr(l + 1, r - l - 1);
            }
            
            // "abba"
            l = i;
            r = i + 1;
            while (l >= 0 && r < length && s[l] == s[r]) {
                l--;
                r++;
            }
            if (answer.length() < r - l - 1) {
                answer = s.substr(l + 1, r - l -1);
            }
        }
        
        return answer;
    }
};
