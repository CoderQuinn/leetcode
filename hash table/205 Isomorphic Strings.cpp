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
        unordered_map<char, char> st, ts;
        for(int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            if(st.count(a) && st[a] != b) return false;
            st[a] = b;
            if(ts.count(b) && ts[b] != a) return false;
            ts[b] = a;
        }
        return true;
    }
};
