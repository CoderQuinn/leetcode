//
//  BinaryTreePostorderTraversal.cpp
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
    std::vector<int> result_vector;
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        
        if (curr) {
            postorderTraversal(curr->left);
            postorderTraversal(curr->right);
            result_vector.push_back(curr->val);
        }
        return result_vector;
    }
};

class Solution1 {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result_vector;
        std::stack<TreeNode *> node_stack;
        TreeNode *curr = root;
        TreeNode *visited = nullptr;
        
        while (curr || !node_stack.empty()) {
            
            while (curr) {
                node_stack.push(curr);
                curr = curr->left;
            }
            
            curr = node_stack.top();
            if (!curr->right || visited == curr->right) { // right node is null or has been visited
                visited = node_stack.top();
                result_vector.push_back(visited->val);
                node_stack.pop();
                curr = nullptr;
            } else {
                curr = curr->right;
            }
            
        }
        
        return result_vector;
    }
};
