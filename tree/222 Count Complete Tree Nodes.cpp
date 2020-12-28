//
//  222 Count Complete Tree Nodes.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/28.
//  Copyright © 2020 Quinn. All rights reserved.
//


#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        auto l = root->left, r = root->right;
        int x = 1, y = 1;
        while (l)
        {
            l = l->left;
            x++;
        }

        while (r)
        {
            r = r->right;
            y++;
        }

        if (x == y)
            return (1 << x) - 1;

        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
