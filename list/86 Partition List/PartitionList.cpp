//
//  PartitionList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/15.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        
        ListNode *less_dummy = new ListNode(-1);
        ListNode *more_dummy = new ListNode(-1);
        ListNode *less_tail = less_dummy;
        ListNode *more_tail = more_dummy;
        
        ListNode *ptr = head;
        while (ptr) {
            ListNode *curr = ptr;
            ptr = ptr->next;
            curr->next = nullptr;
            if (curr->val < x) {
                less_tail->next = curr;
                less_tail = curr;
            } else {
                more_tail->next = curr;
                more_tail = curr;
            }
        }
        less_tail->next = more_dummy->next;
        delete more_dummy;
        
        ListNode *result = less_dummy->next;
        delete less_dummy;
        
        return result;
    }
};
