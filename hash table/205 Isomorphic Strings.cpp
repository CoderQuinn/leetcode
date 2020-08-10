//
//  205 Isomorphic Strings.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map1(256, -1); // since the whole ASCII size is 256
        vector<int> map2(256, -1);
        long size = s.size();
        for (int i = 0; i < size; ++i) {
            if (map1[s[i]] != map2[t[i]]) {
                return false;
            }
            // update
            map1[s[i]] = i;
            map2[t[i]] = i;
        }
        return true;
    }
};
