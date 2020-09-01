//
//  13 Roman to Integer.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/29.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };


        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = hash[s[i]];
            if (i + 1 < s.length() && val < hash[s[i + 1]]) {
                val = -val;
            }
            res += val;
        }
        
        return res;
    }
};
