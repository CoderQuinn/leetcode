//
//  173 Binary Search Tree Iterator.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/6.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        left_tree_inorder(root);
    }
    
    void left_tree_inorder(TreeNode *root) {
        while (root) {
            node_stack_.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *curr = node_stack_.top();
        int result = curr->val;
        node_stack_.pop();
        
        if (curr->right) {
            left_tree_inorder(curr->right);
        }
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node_stack_.empty();
    }
private:
    std::stack<TreeNode *> node_stack_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
