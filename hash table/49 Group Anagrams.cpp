//
//  49 Group Anagrams.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/12.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        for(auto &v : strs)
        {
            string key = v;
            sort(key.begin(), key.end());
            if(hash.count(key))
            {
                vector<string> &cur = hash[key];
                cur.push_back(v);
            }
            else
            {
                vector<string> ans({v});
                hash[key] = ans;
            }
        }
        
        for(auto &pair : hash)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};

// 字符串哈希
class Solution1 {
public:
#define MAX_SIZE 26
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int alphas[MAX_SIZE];
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        
        for(auto &v : strs)
        {
            memset(alphas, 0, sizeof alphas);
            string key;
            
            for(auto &ch : v)
            {
                alphas[ch - 'a']++;
            }
            
            for(int i = 0; i < MAX_SIZE; i++)
            {
                if(alphas[i] > 0)
                {
                    key += (i + 'a');
                    key += to_string(alphas[i]);
                }
            }
            
            if(hash.count(key))
            {
                vector<string> &cur = hash[key];
                cur.push_back(v);
            }
            else
            {
                vector<string> ans({v});
                hash[key] = ans;
            }
        }
        
        for(auto &pair : hash)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
