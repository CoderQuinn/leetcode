//
//  Remove Duplicates from Sorted List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        auto prev = head;
        auto curr = head;
        while(curr)
        {
            if(prev->val != curr->val)
            {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = nullptr;
        return head;
    }
};
