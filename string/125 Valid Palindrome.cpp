//
//  125 Valid Palindrome.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    bool check(char c)
    {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }

    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0, j = n - 1; i < j; i++, j--)
        {
            while(i < j && !check(s[i])) i++;
            while(i < j && !check(s[j])) j--;
            if(i < j && tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};
