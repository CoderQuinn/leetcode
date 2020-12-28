//
//  BinaryTreePostorderTraversal.cpp
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
class Solution0
{
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode *root)
    {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *u)
    {
        if (!u)
            return;
        dfs(u->left);
        dfs(u->right);
        ans.push_back(u->val);
    }
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stk;

        TreeNode *p = root, *last = nullptr;
        while (p || !stk.empty())
        {
            while (p)
            {
                stk.push(p);
                p = p->left;
            }

            p = stk.top();
            if (!p->right || last == p->right)
            {
                last = p;
                ans.push_back(p->val);
                stk.pop();
                p = nullptr;
            }
            else
            {
                p = p->right;
            }
        }

        return ans;
    }
};
