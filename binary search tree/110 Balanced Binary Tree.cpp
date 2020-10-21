//
//  110 Balanced Binary Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/9.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <algorithm>    // std::max
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

// 自顶向下
class Solution {
public:
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode *root, bool &ans) {
        if (!root) return 0;
        int lh = dfs(root->left, ans), rh = dfs(root->right, ans);
        if(abs(lh - rh) > 1)
            ans = false;
        return 1 + max(lh, rh);
    }
};

// 尾递归
class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }
    
    bool dfs(TreeNode *root, int &depth) {
        if(!root)
        {
            depth = 0;
            return true;
        }
        
        int lh = 0, rh = 0;
        if(!dfs(root->left, lh) || !dfs(root->right, rh)) return false;

        if(abs(lh - rh) > 1) return false;
        depth = max(lh, rh) + 1;
        return true;
    }
};
