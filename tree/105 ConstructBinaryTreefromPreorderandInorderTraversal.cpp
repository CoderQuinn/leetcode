//
//  ConstructBinaryTreefromPreorderandInorderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace::std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl > pr) return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);
        int k = 0;
        for(; il + k <= ir; k++)
        {
            if(inorder[il + k] == root->val)
                break;
        }
        root->left = build(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
        root->right = build(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
        
        return root;
    }
};

// hash_map加速
class Solution1 {
public:
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl > pr) return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);
        int k = pos[root->val] - il;
        root->left = build(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
        root->right = build(preorder, inorder, pl + k + 1, pr, il + k+ 1, ir);

        return root;
    }
};
