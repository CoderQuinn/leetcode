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

// recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode *root, long left_val, long right_val)
    {
        if(!root) return true;
        if(root->val <= left_val || root->val >= right_val)
            return false;
        return dfs(root->left, left_val, root->val) && dfs(root->right, root->val, right_val);
    }
};

// inorder traversal
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        long prev = LONG_MIN;
        TreeNode *curr = root;
        stack<TreeNode *> stk;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            if (curr->val <= prev) {
                return false;
            }
            prev = curr->val;
            curr = curr->right;
        }
        
        return true;
        
    }
};

