//
//  450 Delete Node in a BST.cpp
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

//1. 如果目标节点没有子节点，我们可以直接移除该目标节点。
//2. 如果目标节只有一个子节点，我们可以用其子节点作为替换。
//3. 如果目标节点有两个子节点，我们需要用其中序后继节点或者前驱节点来替换，再删除该目标节点。

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else{
            
            if (root->left && root->right) {
                // 1. find the min val of right tree
                
//                TreeNode *next_node = find_min_node(root->right);
//                root->val = next_node->val;
//                root->right = deleteNode(root->right, root->val);
                
                // 2. find the max val of left tree
                TreeNode *next_node = find_max_node(root->left);
                root->val = next_node->val;
                root->left = deleteNode(root->left, root->val);
            } else {
                TreeNode *tmp = root;
                if(!root->left) {
                    root = root->right;
                } else if(!root->right) {
                    root = root->left;
                }
                delete tmp;
            }
        }
        return root;
    }
    
    TreeNode *find_min_node(TreeNode *root) {
        if (!root) return nullptr;
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    
    TreeNode *find_max_node(TreeNode *root) {
        if (!root) return nullptr;
        if (!root->right) return root;
        else return find_max_node(root->right);
    }
};
