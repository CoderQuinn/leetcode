//
//  226 Invert Binary Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        auto tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
