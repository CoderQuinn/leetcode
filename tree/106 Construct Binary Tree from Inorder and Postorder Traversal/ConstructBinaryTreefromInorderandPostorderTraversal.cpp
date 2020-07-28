//
//  ConstructBinaryTreefromInorderandPostorderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
#include <stack>
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
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if (inorder.empty() || inorder.empty() || inorder.size() != postorder.size()) return nullptr;
     
//         return build_tree_core(inorder, 0, postorder, 0, inorder.size());
         return build_tree_core(inorder.begin(), postorder.begin(), inorder.size());
     }
     
     TreeNode* build_tree_core(vector<int>& inorder, int in_begin, vector<int>& postorder, int pos_begin, size_t size) {
         if (size <= 0) return nullptr;
         
         int root_val = postorder[pos_begin + (size - 1)];
         TreeNode *root = new TreeNode(root_val);
    
         int i = 0;
         while (i < size) {
             if (root_val == inorder[in_begin + i]) {
                 break;
             }
             ++i;
         }

         root->left = build_tree_core(inorder, in_begin, postorder, pos_begin, i);
         root->right = build_tree_core(inorder, in_begin + i + 1, postorder, pos_begin + i, size - i - 1);
         
         return root;
     }
    
     TreeNode* build_tree_core(vector<int>::iterator in_iter, vector<int>::iterator pos_iter, size_t size) {
         if (size <= 0) return nullptr;
         
         int root_val = *(pos_iter + size - 1);
         TreeNode *root = new TreeNode(root_val);
    
         int i = 0;
         while (i < size) {
             if (root_val == *(in_iter + i)) {
                 break;
             }
             ++i;
         }

         root->left = build_tree_core(in_iter, pos_iter, i);
         root->right = build_tree_core(in_iter + i + 1, pos_iter + i, size - i - 1);
         
         return root;
     }
};
