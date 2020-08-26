//
//  9 Palindrome Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/24.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        return str == string(str.rbegin(), str.rend());
    }
};

class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x;
        long y = 0;
        while (tmp) {
            y = 10 * y + tmp % 10;
            tmp /= 10;
        }
        
        return y == x;
    }
};
