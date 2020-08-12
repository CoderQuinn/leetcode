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
        vector<vector<string>> result_vector;
        unordered_map<string, vector<string>> hash_map;
        
        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            
            if (hash_map.count(key) > 0) {
                hash_map[key].push_back(str);
            } else {
                vector<string> val = { str };
                hash_map[key] = val;
            }
        }
        
        for (auto pair : hash_map) {
            result_vector.push_back(pair.second);
        }

        return result_vector;
    }
};

class Solution1 {
public:
#define ALPHA_MAX_SIZE 26
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result_vector;
        unordered_map<string, vector<string>> hash_map;
        
        for (auto str : strs) {
            int alpha[ALPHA_MAX_SIZE] = {0};
            string key;
            for (auto ch : str) {
                alpha[ch - 'a'] += 1;
            }
            
            for (int i = 0; i < ALPHA_MAX_SIZE; ++i) {
                key += '#';
                key += to_string(alpha[i]);
            }

            if (hash_map.count(key) > 0) {
                hash_map[key].push_back(str);
            } else {
                vector<string> val = { str };
                hash_map[key] = val;
            }
        }
        
        for (auto pair : hash_map) {
            result_vector.push_back(pair.second);
        }

        return result_vector;
    }
};
