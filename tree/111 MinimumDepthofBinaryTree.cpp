//
//  MinimumDepthofBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <climits>
#include <algorithm>    // std::minmax
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
class Solution0 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ret = INT_MAX;
        minimum_depth(root, 1, ret);

        return ret;
    }
    
    void minimum_depth(TreeNode* root, int depth, int &result) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            result = min(result, depth);
        } else {
            minimum_depth(root->left, depth + 1, result);
            minimum_depth(root->right, depth + 1, result);
        }
        
    }
};

class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        int ret = INT_MAX;
        if (root->left) {
            ret = min(minDepth(root->left), ret);
        }
        
        if (root->right) {
            ret = min(ret, minDepth(root->right));
        }

        return ret + 1;
    }
    
};
