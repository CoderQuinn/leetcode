//
//  TreeNode.h
//  Leetcode
//
//  Created by Quinn on 2020/7/26.
//  Copyright © 2020 Quinn. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

#endif /* TreeNode_h */
