//
//  3 Longest Substring Without Repeating Characters.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash_set;
        int j = -1;
        long n = s.length();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                hash_set.erase(s[i - 1]);
            }
            
            while (j + 1 < n && hash_set.count(s[j + 1]) <= 0) {
                hash_set.insert(s[j + 1]);
                ++j;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};
