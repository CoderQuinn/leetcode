//
//  78 Subsets.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/20.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        auto n = nums.size();
        for (int i = 0; i < 1 << n; i++) {
            vector<int> path;
            for (int j = 0; j < n; j++) {
                if(i >> j & 1)
                    path.push_back(nums[j]);
            }
            res.push_back(path);
        }
        return res;
    }
};

class Solution1 {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int u)
    {
        if(u == nums.size())
        {
            res.push_back(path);
            return;
        }
        
        // 不选择当前
        dfs(nums, u + 1);
        
        // 选择当前
        path.push_back(nums[u]);
        dfs(nums, u + 1);
        path.pop_back();
    }
};
