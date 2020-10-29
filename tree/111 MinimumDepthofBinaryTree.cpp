//
//  MinimumDepthofBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <climits>
#include <algorithm>    // std::minmax
using namespace std;
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MAX;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *root, int depth, int &res)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            res = min(depth + 1, res);
            return;
        }
        dfs(root->left, depth + 1, res);
        dfs(root->right, depth + 1, res);
    }
};

class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int res = INT_MAX;
        if(root->left)
        {
            res = min(minDepth(root->left), res);
        }
        if(root->right)
        {
            res = min(minDepth(root->right), res);
        }
        return res + 1;
    }
};
