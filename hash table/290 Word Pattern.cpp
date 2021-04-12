//
//  290 Word Pattern.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/8.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ssin(s);
        string w;
        while(ssin >> w) words.push_back(w);
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;

        if(pattern.size() != words.size()) return false;
        
        int n = pattern.size();
        for(int i = 0; i < n; i++)
        {
            auto w = words[i];
            auto c = pattern[i];

            if(!ps.count(c)) ps[c] = w;
            else if(ps[c] != w) return false;

            if(!sp.count(w)) sp[w] = c;
            else if(sp[w] != c) return false;
        }
        return true;
        
    }
};
