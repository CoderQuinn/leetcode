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
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(level);
        }
        return res;
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
