//
//  ValidateBinarySearchTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/5.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <stack>
#include <climits>
using namespace std;

// inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        TreeNode *curr = root;
        std::stack<TreeNode *> node_stack;
        
        long long prev_val = LLONG_MIN;
        while (curr || !node_stack.empty()) {
            while (curr) {
                node_stack.push(curr);
                curr = curr->left;
            }
            
            curr = node_stack.top();
            if (prev_val >= curr->val) {
                return false;
            }
            prev_val = curr->val;
            node_stack.pop();
            curr = curr->right;
        }
        
        return true;
        
    }
};

// recursion
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool helper(TreeNode *root, long long min_val, long long max_val) {
        if (!root) return true;
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }
        return helper(root->left, min_val, root->val) && helper(root->right, root->val, max_val);
    }
};
