//
//  95 Unique Binary Search Trees II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return {};
        else
            return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int l, int r)
    {
        if(l > r) return {nullptr};
        vector<TreeNode*> res;
        for(int i = l; i <= r; i++) // 枚举根节点
        {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for(auto p : left)
            {
                for(auto q: right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = p;
                    root->right = q;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
};
