//
//  39 Combination Sum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }
    
    void dfs(vector<int>& candidates, int u, int target)
    {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        
        if (u == candidates.size()) {
            return;
        }
        
        for (int i = 0; candidates[u] * i <= target; i++) {
            dfs(candidates, u + 1, target - candidates[u] * i);
            path.push_back(candidates[u]);
        }
        
        for (int i = 0; candidates[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};
