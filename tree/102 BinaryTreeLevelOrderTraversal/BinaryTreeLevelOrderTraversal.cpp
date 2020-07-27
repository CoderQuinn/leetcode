//
//  BinaryTreeLevelOrderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <queue>
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

// BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> result_vec;
        if (!root) return result_vec;
        
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            auto current_level_size = queue.size();
            result_vec.push_back(vector<int>());
            for (decltype(current_level_size) i = 0; i < current_level_size; ++i) {
                TreeNode *curr = queue.front();
                queue.pop();
                result_vec.back().push_back(curr->val);
                if (curr->left) queue.push(curr->left);
                if (curr->right) queue.push(curr->right);
            }
        }
        return result_vec;
    }
};

// DFS
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> result_vec;
        DFS(result_vec, 0, root);
        return result_vec;
    }
    
    void DFS(vector<vector<int>>& vec, int level, TreeNode* root) {
        if (!root) return;
        
        if (vec.size() <= level)
            vec.push_back(vector<int>());
        vec[level].push_back(root->val);
        DFS(vec, level + 1, root->left);
        DFS(vec, level + 1, root->right);
    }
};

