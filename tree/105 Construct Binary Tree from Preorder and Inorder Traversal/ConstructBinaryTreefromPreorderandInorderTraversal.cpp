//
//  ConstructBinaryTreefromPreorderandInorderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty() || inorder.empty() || inorder.size() != preorder.size()) return nullptr;
        
        return build_tree_core(preorder.begin(), inorder.begin(), inorder.size());
    }
    
    TreeNode* build_tree_core(vector<int>::iterator pre_iter, vector<int>::iterator in_iter, size_t size) {
        if (size <= 0) return nullptr;
        
        int root_val = *pre_iter;
        TreeNode *root = new TreeNode(root_val);
        
        int i = 0;
        while (i < size) {
            if (root_val == *(in_iter + i)) {
                break;
            }
            ++i;
        }
        
        root->left = build_tree_core(pre_iter + 1, in_iter, i);
        root->right = build_tree_core(pre_iter + i + 1, in_iter + i + 1, size - i - 1);
        
        return root;
    }
};

// 使用hash_map加速查找
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty() || inorder.empty() || inorder.size() != preorder.size()) return nullptr;

        for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it) {
            index[*it] = it;
        }
        
        return build_tree_core(preorder.begin(), inorder.begin(), inorder.size());
    }
    
    TreeNode* build_tree_core(vector<int>::iterator pre_iter, vector<int>::iterator in_iter, size_t size) {
        if (size <= 0) return nullptr;
        
        int root_val = *pre_iter;
        TreeNode *root = new TreeNode(root_val);
        
        vector<int>::iterator target_it = index[root_val];
        auto i = target_it - in_iter;
        root->left = build_tree_core(pre_iter + 1, in_iter, i);
        root->right = build_tree_core(pre_iter + i + 1, in_iter + i + 1, size - i - 1);
        
        return root;
    }
private:
    unordered_map<int, vector<int>::iterator> index;
    
};
