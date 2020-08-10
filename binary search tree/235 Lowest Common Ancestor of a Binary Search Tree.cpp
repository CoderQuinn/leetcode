//
//  235 Lowest Common Ancestor of a Binary Search Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/8.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// iteration
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode *node = root;
        while (node) {
            if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else {
                return node;
            }
        }
        
        return nullptr;
    }
};

// recursion
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};
