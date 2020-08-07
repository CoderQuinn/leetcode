//
//  PathSum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum == root->val;
        int new_sum = sum - root->val;
        if (new_sum < 0) return false;
        return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
    }
};
