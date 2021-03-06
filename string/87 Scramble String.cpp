//
//  87 Scramble String.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        string bs1 = s1, bs2 = s2;
        sort(bs1.begin(), bs1.end());
        sort(bs2.begin(), bs2.end());
        
        if(bs1 != bs2)
            return false;
        
        int n = s1.size();
        for(int i = 1; i <= n - 1; i++)
        {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        return false;
    }
};
