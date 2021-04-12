//
//  242 Valid Anagram.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/30.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> table(26, 0);
        for(auto &c : s) table[c - 'a']++;
        for(auto &c : t)
        {
            int t = c - 'a';
            table[t]--;
            if(table[t] < 0) return false;
        }
        return true;
    }
};
