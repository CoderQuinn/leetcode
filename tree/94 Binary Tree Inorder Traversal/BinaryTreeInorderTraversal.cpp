//
//  BinaryTreeInorderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/26.
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
    std::vector<int> result_vec;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        if (curr) {
            inorderTraversal(curr->left);
            result_vec.push_back(curr->val);
            inorderTraversal(curr->right);
        }
        
        return result_vec;
    }
};

class Solution1 {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result_vec;
        std::stack<TreeNode *> node_stack;
        TreeNode *curr = root;

        while (curr || !node_stack.empty()) {
            while (curr) {
                node_stack.push(curr);
                curr = curr->left;
            }
            
            if (!node_stack.empty()) {
                curr = node_stack.top();
                result_vec.push_back(curr->val);
                node_stack.pop();
                curr = curr->right;
            }
        }
        
        return result_vec;
    }
};
