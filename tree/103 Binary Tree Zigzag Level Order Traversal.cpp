//
//  103 Binary Tree Zigzag Level Order Traversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/22.
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        int cnt = 0;
        while(!q.empty())
        {
            int len = q.size();
            vector<int> level;
            for(int i = 0; i < len; i++)
            {
                auto curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(cnt++ % 2) reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};
