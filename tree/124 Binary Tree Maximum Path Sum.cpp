//
//  124 Binary Tree Maximum Path Sum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <climits>
#include <algorithm>
using namespace::std;

class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root)
    {
        if(!root) return 0;
        int left = max(0, dfs(root->left)), right = max(0, dfs(root->right)); // < 0, 不选择当前路径
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }
};
