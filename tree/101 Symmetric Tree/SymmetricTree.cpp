//
//  SymmetricTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <queue>
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
class Solution0 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return is_symmetric_core(root->left, root->right);
    }
    
    bool is_symmetric_core(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && is_symmetric_core(left->left, right->right) && is_symmetric_core(left->right, right->left);
    }
    
};

// levelOrder

class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode *> queue;
        if (!root) return true;

        queue.push(root->left);
        queue.push(root->right);
        while (!queue.empty()) {
            TreeNode *left = queue.front();
            queue.pop();
            TreeNode *right = queue.front();
            queue.pop();
            
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            
            queue.push(left->left);
            queue.push(right->right);
            
            queue.push(left->right);
            queue.push(right->left);
            
        }
        return true;
        
    }
    
};
