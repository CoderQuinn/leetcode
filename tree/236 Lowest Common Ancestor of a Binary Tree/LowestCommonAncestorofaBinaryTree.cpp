//
//  LowestCommonAncestorofaBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
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

/*
 所有节点的值都是唯一的。
 p、q 为不同节点且均存在于给定的二叉树中。
 1. pq位于两个左右不同的子树上
 2. p为祖先，q在其左子树或右子树上
 3. q为祖先，p在其左子树或右子树上
 4. root的左右子树均不包含pq,与题意不符
 */
// 递归
class Solution0 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || q == root || p == root) return root;
        TreeNode *left_result = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_result = lowestCommonAncestor(root->right, p, q);
        if (!left_result) { // p,q位于右子树上
            return right_result;
        }
        else if (!right_result) { // p,q位于左子树上
            return left_result;
        }
        return root;
    }
};

// 迭代
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || q == root || p == root) return root;
        // todo:
        return root;
    }
};
