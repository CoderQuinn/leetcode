//
//  90 Subsets II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
        
        int k = u + 1;
        while(k < nums.size() && nums[k] == nums[u]) k++;
        
        for(int i = 0; i <= k - u; i++)
        {
            dfs(nums, k);
            path.push_back(nums[u]);
        }
        
        for(int i = 0; i <= k - u; i++)
        {
            path.pop_back();
        }
        
    }
};

class Solution1
{
public:
    unordered_map<int, int> cnt;
    vector<vector<int> > ans;
    vector<int> path;
    
    vector<vector<int> > subsetsWithDup(vector<int> &nums)
    {
        for (auto &x : nums)
            cnt[x]++;
        dfs(-10);
        return ans;
    }
    
    void dfs(int u)
    {
        if (u > 10)
            ans.push_back(path);
        else
        {
            for (int i = 0; i < cnt[u] + 1; i++)
            {
                dfs(u + 1);
                path.push_back(u);
            }
            
            for (int i = 0; i < cnt[u] + 1; i++)
            {
                path.pop_back();
            }
        }
    }
};
