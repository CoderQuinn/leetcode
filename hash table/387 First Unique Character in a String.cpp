//
//  387 First Unique Character in a String.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int result = -1;
        
        unordered_map<char, int> hash_map;
        for (int i = 0; i < s.size(); ++i) {
            if (hash_map.count(s[i])) {
                hash_map[s[i]] = -1;
            } else {
                hash_map[s[i]] = i;
            }
        }
        
        for (auto ch : s) {
            if (hash_map[ch] != -1) {
                result = hash_map[ch];
                break;
            }
        }
        
        return result;
    }
};
