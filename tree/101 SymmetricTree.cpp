//
//  SymmetricTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode *l, TreeNode *r)
    {
        if(!l && !r) return true;
        if(!l || !r || l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
};

// levelOrder

class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return true;
    }

};
