//
//  40 Combination Sum II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
    
    void dfs(vector<int>& candidates, int u, int target)
    {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        
        if (u == candidates.size()) {
            return;
        }
        
        int k = u + 1;
        while (k < candidates.size() && candidates[k] == candidates[u]) {
            k++;
        }
        
        int cnt = k - u;
        
        for (int i = 0; candidates[u] * i <= target && i <= cnt; i++) {
            dfs(candidates, k, target - candidates[u] * i);
            path.push_back(candidates[u]);
        }
        
        for (int i = 0; candidates[u] * i <= target && i <= cnt; i++) {
            path.pop_back();
        }
    }
};
