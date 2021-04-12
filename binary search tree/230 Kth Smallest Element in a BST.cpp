//
//  230 Kth Smallest Element in a BST.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
    int cnt, ans;
    int kthSmallest(TreeNode *root, int k)
    {
        cnt = k;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        if (--cnt == 0)
        {
            ans = root->val;
            return;
        }
        dfs(root->right);
    }
};
