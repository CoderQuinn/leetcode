//
//  LowestCommonAncestorofaBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <unordered_map>
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

/*
 所有节点的值都是唯一的。
 p、q 为不同节点且均存在于给定的二叉树中。
 1. pq位于两个左右不同的子树上
 2. p为祖先，q在其左子树或右子树上
 3. q为祖先，p在其左子树或右子树上
 4. root的左右子树均不包含pq,与题意不符
 */

// 存储父节点
class Solution0
{
public:
    unordered_map<TreeNode *, TreeNode *> fa;
    unordered_map<TreeNode *, bool> vt;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        fa[root] = nullptr;
        dfs(root);

        TreeNode *cur = p;
        while (cur)
        {
            vt[cur] = true;
            cur = fa[cur];
        }

        cur = q;
        while (cur)
        {
            if (vt[cur])
                return cur;
            cur = fa[cur];
        }

        return root;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;

        if (root->left)
        {
            fa[root->left] = root;
            dfs(root->left);
        }

        if (root->right)
        {
            fa[root->right] = root;
            dfs(root->right);
        }
    }
};

// 递归
class Solution
{
public:
    TreeNode *ans = nullptr;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }

    int dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return 0x00;
        int state = dfs(root->left, p, q);

        if (p == root)
            state |= 0x01;
        else if (q == root)
            state |= 0x10;

        state |= dfs(root->right, p, q);

        if (state == 0x11 && !ans)
        {
            ans = root;
        }

        return state;
    }
};
