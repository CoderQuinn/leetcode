//
//  108 Convert Sorted Array to Binary Search Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <vector>
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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted_array_to_bst_helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode *sorted_array_to_bst_helper(vector<int>& nums, long left, long right) {
        if (left > right) {
            return nullptr;
        }
        
        long mid = left + (right - left) / 2;
        
        TreeNode *root = new TreeNode(nums[mid]);
        
        root->left = sorted_array_to_bst_helper(nums, left, mid - 1);
        root->right = sorted_array_to_bst_helper(nums, mid + 1, right);
        return root;
    }
};
