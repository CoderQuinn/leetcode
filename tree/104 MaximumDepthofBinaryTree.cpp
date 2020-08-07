//
//  MaximumDepthofBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <queue>
#include <stack>
using namespace::std;

// not a tail recursion because it does some computation after the recursive call returned.
class Solution0 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
 自顶向下
1. return specific value for null node
2. update the answer if needed                      // anwer <-- params
3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed                      // answer <-- left_ans, right_ans
 
 1. return if root is null
 2. if root is a leaf node:
 3.      answer = max(answer, depth)         // update the answer if needed
 4. maximum_depth(root.left, depth + 1)      // call the function recursively for left child
 5. maximum_depth(root.right, depth + 1)     // call the function recursively for right child
*/
class Solution1 { // this is a tail recursion because the final instruction is the recursive call.
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        max_depth_core(root, 1, result);
        return result;
    }

    void max_depth_core(TreeNode *root, int depth, int &answer) {
        if (!root) return;
        if (!root->left && !root->right) {
            answer = max(depth, answer);
        }
        
        max_depth_core(root->left, depth + 1, answer);
        max_depth_core(root->right, depth + 1, answer);
    }
};


