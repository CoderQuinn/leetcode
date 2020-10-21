//
//  76 Minimum Window Substring.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/20.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, hash;
        for(auto v : t)
        {
            hash[v]++;
        }
        
        string res;
        int cnt = 0;
        for(int i = 0, j = 0; i < s.size(); i++)
        {
            window[s[i]]++;
            if(window[s[i]] <= hash[s[i]])
                cnt++;
            
            while(window[s[j]] > hash[s[j]])
                window[s[j++]]--;
            
            if(cnt == t.size())
            {
                if(res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        
        return res;
    }
};
