//
//  BinaryTreePreorderTraversal.cpp
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

// recursively
class Solution {
public:
    std::vector<int> result_vector;
    vector<int> preorderTraversal(TreeNode* root) {
        
        TreeNode *curr = root;
        if (curr) {
            result_vector.push_back(curr->val);
            preorderTraversal(curr->left);
            preorderTraversal(curr->right);
        }
        
        return result_vector;
    }
};

// iteratively
class Solution1 {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result_vector;
        std::stack<TreeNode *> node_stack;
        
        TreeNode *curr = root;
        while (curr || !node_stack.empty()) {
            while (curr) {
                result_vector.push_back(curr->val);
                node_stack.push(curr);
                curr = curr->left;
            }
            
            if (!node_stack.empty()) {
                curr = node_stack.top();
                node_stack.pop();
                curr = curr->right;
            }
        }
        return result_vector;
    }
};
