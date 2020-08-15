//
//  BinaryTreeLevelOrderTraversalII.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result_vector;
        if (!root) return result_vector;
        queue<TreeNode *> node_queue;
        
        node_queue.push(root);
        while (!node_queue.empty()) {
            auto size = node_queue.size();
            result_vector.push_back(vector<int>());
            
            for (decltype(size) i = 0; i < size; ++i) {
                TreeNode *curr = node_queue.front();
                node_queue.pop();
                result_vector.back().push_back(curr->val);
                
                if (curr->left) {
                    node_queue.push(curr->left);
                }
                
                if (curr->right) {
                    node_queue.push(curr->right);
                }
            }
        }
        reverse(result_vector.begin(), result_vector.end());
        return result_vector;
    }
};
