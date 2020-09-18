//
//  46 Permutations.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited;
    
    void dfs(int n, vector<int>& nums)
    {
        if (n == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                path[n] = nums[i];
                dfs(n + 1, nums);
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        visited.resize(size);
        path.resize(size);
        dfs(0, nums);
        return res;
    }
};
