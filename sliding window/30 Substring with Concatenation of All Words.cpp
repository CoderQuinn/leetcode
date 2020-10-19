//
//  30 Substring with Concatenation of All Words.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        
        auto n = s.length(), m = words.size(), w = words[0].size();
        
        unordered_map<string, int> total;
        for(auto &word : words)
        {
            total[word]++;
        }
        
        for(int i = 0; i < w; i++)
        {
            unordered_map<string, int> window;
            int cnt = 0;
            for(int j = i; j + w <= n; j += w)
            {
                if(j - i >= m * w){
                    string word = s.substr(j - m * w, w);
                    if(window[word] <= total[word]) cnt--;
                    window[word]--;
                }
                string word = s.substr(j, w);
                if(window[word] < total[word]) cnt++;
                window[word]++;
                if(cnt == m) res.push_back(j - (m - 1) * w);
            }
        }
        
        return res;
    }
};
