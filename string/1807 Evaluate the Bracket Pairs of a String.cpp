//
//  1807 Evaluate the Bracket Pairs of a String.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/29.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hash;
        for(auto &v : knowledge) hash[v[0]] = v[1];
        string res;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '(')
                res += s[i];
            else
            {
                int j = i + 1;
                string key;
                while(j < s.size() && s[j] != ')') key += s[j++];
                i = j;
                
                if(hash.count(key)) res += hash[key];
                else res += '?';
            }
        }
        
        return res;
    }
};
