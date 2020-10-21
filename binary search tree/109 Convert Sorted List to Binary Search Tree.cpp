//
//  109 Convert Sorted List to Binary Search Tree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        
        int n = 0;
        ListNode *p = head;
        while(p)
        {
            p = p->next;
            ++n;
        }
        
        p = head;
        for(int i = 0; i < n / 2 - 1; i++)
        {
            p = p->next;
        }
        
        TreeNode *root = new TreeNode(p->next->val);
        root->right = sortedListToBST(p->next->next);
        p->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};
