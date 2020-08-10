//
//  110 Balanced Binary Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/9.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <algorithm>    // std::max
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

// 自顶向下
class Solution {
public:
    int heigth(TreeNode *root) {
        if (!root) return 0;
        
        return 1 + max(heigth(root->left) , heigth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        return abs(heigth(root->left) - heigth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

// 自底向上
class Solution1 {
public:
    bool is_balanced_helper(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }
        int left_height = 0, right_height = 0;
        if (is_balanced_helper(root->left, left_height) && is_balanced_helper(root->right, right_height)) {
            if (abs(left_height - right_height) <= 1) {
                height = max(left_height, right_height) + 1;
                return true;
            }
        }
        return false;
    }
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return is_balanced_helper(root, height);
    }
};
