//
//  701 Insert into a Binary Search Tree.cpp
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 时间复杂度: 平均时间复杂度O(logN)，平均空间复杂度：O(logn)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        if (val > root->val) {
           root->right = insertIntoBST(root->right, val);
        } else if(val < root->val) {
           root->left  = insertIntoBST(root->left, val);
        }
        
        return root;
    }
};

// 时间复杂度: 平均时间复杂度O(logN)，空间复杂度：O(1)
class Solution1 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        while (curr) {
            prev = curr;
            if (curr->val == val) {
                return curr;
            } else if (curr->val < val) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        if (val < prev->val) {
            prev->left = new TreeNode(val);
        } else if(val > prev->val) {
            prev->right = new TreeNode(val);
        }
        return root;
    }
};
