//
//  BinaryTreePreorderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
#include <stack>
using namespace::std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursively
class Solution0 {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *u) {
        if(!u) return;
        ans.push_back(u->val);
        dfs(u->left);
        dfs(u->right);
    }
};

// iteratively
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stk;

        while (root || !stk.empty())
        {
            while (root)
            {
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return ans;
    }
};
