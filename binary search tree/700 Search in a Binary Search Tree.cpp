//
//  700 Search in a Binary Search Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/6.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 时间复杂度: 平均时间复杂度O(logN) 空间复杂度：O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *curr = root;
        while (curr) {
            if (curr->val == val) {
                return curr;
            } else if (curr->val < val) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        return nullptr;
    }
};

// 时间复杂度: 平均时间复杂度O(logN)，空间复杂度：O(logn)
class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;

        if (root->val == val) {
            return root;
        }
        
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        
        return searchBST(root->right, val);
    }
};
