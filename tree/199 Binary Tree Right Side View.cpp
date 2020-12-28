//
//  199 Binary Tree Right Side View.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                auto p = q.front();
                q.pop();
                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
                if(i == len - 1) {
                    res.push_back(p->val);
                }
            }
        }
        return res;
    }
};
