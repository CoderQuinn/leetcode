//
//  114 Flatten Binary Tree to Linked List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/29.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"


class Solution {
public:
    void flatten(TreeNode* root) {
        while(root)
        {
            auto curr = root->left;
            if(curr)
            {
                while(curr->right) curr = curr->right;
                curr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
