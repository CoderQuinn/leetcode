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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode *root)
    {
        if(!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};

class Solution1 {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode * curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};
