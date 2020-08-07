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
// 1.递归
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

// 2.迭代
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || q == root || p == root) return root;
        
        unordered_map<int, TreeNode*> traversal_map;
        traversal_map[root->val] = nullptr;
        DFS(root, traversal_map);
        
        unordered_map<TreeNode*, bool> visited_map;
        TreeNode *curr = p;
        while (curr) {
            visited_map[curr] = true;
            curr = traversal_map[curr->val];
        }
        
        curr = q;
        while (curr) {
            if (visited_map[curr]) {
                return curr;
            }
            curr = traversal_map[curr->val];
        }
        
        return root;
    }
    
    void DFS(TreeNode* root, unordered_map<int, TreeNode*> &map){
        if (root->left) {
            map[root->left->val] = root;
            DFS(root->left, map);
        }
        
        if (root->right) {
            map[root->right->val] = root;
            DFS(root->right, map);
        }
    }
};
