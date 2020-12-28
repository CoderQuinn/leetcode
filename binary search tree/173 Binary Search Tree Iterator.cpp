//
//  173 Binary Search Tree Iterator.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/6.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <stack>
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
class BSTIterator
{
public:
    stack<TreeNode *> stk;
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *root = stk.top();
        int res = root->val;
        stk.pop();
        root = root->right;
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
        return res;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
