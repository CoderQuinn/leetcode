//
//  99 Recover Binary Search Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode *last = nullptr, *first = nullptr, *second = nullptr;
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(first && second)
            swap(first->val, second->val);
    }
    
    void dfs(TreeNode *u)
    {
        if(!u) return;
        dfs(u->left);
        if(last && u->val < last->val)
        {
            if(!first)
            {
                first = last;
                second = u;
            }
            else
            {
                second = u;
            }
        }
        last = u;
        dfs(u->right);
    }
};

// morris遍历
class Solution1 {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *last = nullptr, *l = nullptr, *r = nullptr;
        while(root)
        {
            if(!root->left)
            {
                if(last && root->val < last->val)
                {
                    if(!l)
                        l = last;
                    r = root;
                }
                last = root;
                root = root->right;
            }
            else
            {
                auto p = root->left;
                while(p->right && p->right != root)
                    p = p->right;
                if(!p->right)
                {
                    p->right = root;
                    root = root->left;
                }
                else
                {
                    p->right = nullptr;
                    if(last && root->val < last->val)
                    {
                        if(!l)
                            l = last;
                        r = root;
                    }
                    last = root;
                    root = root->right;
                }
                
            }
        }
        
        if(l && r)
            swap(l->val, r->val);
    }
};
