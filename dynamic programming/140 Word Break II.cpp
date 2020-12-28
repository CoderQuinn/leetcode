//
//  140 Word Break II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/11/29.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<bool> f;
    unordered_set<string> hash;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        f.resize(n + 1);
        for(auto word : wordDict) {
            hash.insert(word);
        }
        f[n] = true;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(hash.count(s.substr(i, j - i + 1)) && f[j + 1]) {
                    f[i] = true;
                }
            }
        }
        
        dfs(s, 0, "");
        return ans;
    }
    
    void dfs(string &s, int u, string path) {
        int n = s.size();
        if(u == n) {
            path.pop_back();
            ans.push_back(path);
        } else {
            for(int j = u; j < n; j++) {
                if(hash.count(s.substr(u, j - u + 1)) && f[j + 1]) {
                    dfs(s, j + 1, path + s.substr(u, j - u + 1) + " ");
                }
            }
        }
    }
};
