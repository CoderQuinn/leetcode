//
//  ConstructBinaryTreefromInorderandPostorderTraversal.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/28.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
#include <unordered_map>
using namespace::std;

// hash加速
class Solution {
public:
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            pos[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr)
    {
        if(pl > pr) return nullptr;
        TreeNode *root = new TreeNode(postorder[pr]);
        int k = pos[postorder[pr]] - il;
        root->left = build(inorder, postorder, il, il + k - 1, pl, pl + k - 1);
        root->right = build(inorder, postorder, il + k + 1, ir, pl + k, pr - 1);
        return root;
    }
};

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr)
    {
        if(pl > pr) return nullptr;
        TreeNode *root = new TreeNode(postorder[pr]);
        int k = 0;
        for(; il + k <= ir; k++)
        {
            if(inorder[il + k] == postorder[pr])
                break;
        }
        root->left = build(inorder, postorder, il, il + k - 1, pl, pl + k - 1);
        root->right = build(inorder, postorder, il + k + 1, ir, pl + k, pr - 1);
        return root;
    }
};
