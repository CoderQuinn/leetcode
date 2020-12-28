//
//  129 Sum Root to Leaf Numbers.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
using namespace::std;

class Solution {
public:
    int ans;
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode *u, int number)
    {
        if(!u) return;
        number = number * 10 + u->val;
        if(!u->left && !u->right)
            ans += number;
        dfs(u->left, number);
        dfs(u->right, number);
    }
};
