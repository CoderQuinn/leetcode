//
//  113 Path Sum II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/29.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode *root, int sum)
    {
        if(!root)
            return;
        path.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right)
        {
            if(sum == 0)
                ans.push_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();

    }
};
