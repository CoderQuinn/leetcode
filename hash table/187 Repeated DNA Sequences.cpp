//
//  187 Repeated DNA Sequences.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> hash;
        
        for (int i = 0; i + 10 <= s.size(); i++) {
            hash[s.substr(i, 10)]++;
        }
        
        for (auto [s, t] : hash) {
            if(t > 1) {
                res.push_back(s);
            }
        }
        
        return res;
    }
};
