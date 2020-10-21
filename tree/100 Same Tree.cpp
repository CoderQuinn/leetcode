//
//  100 Same Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
using namespace::std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
