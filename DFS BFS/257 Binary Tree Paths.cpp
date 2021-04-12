//
//  257 Binary Tree Paths.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/30.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<string> ans;
    vector<int> path;
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root)
            dfs(root);
        return ans;
    }
    
    void dfs(TreeNode *root)
    {
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            string line = to_string(path[0]);
            for (int i = 1; i < path.size(); i++)
            {
                line += "->" + to_string(path[i]);
            }
            ans.push_back(line);
        }
        else
        {
            if (root->left)
                dfs(root->left);
            if (root->right)
                dfs(root->right);
        }
        path.pop_back();
    }
};
