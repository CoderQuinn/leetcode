//
//  SwapNodesinPairs.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/23.
//  Copyright © 2020 Quinn. All rights reserved.
//
#include "ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy_head = new ListNode(-1);
        ListNode *prev = dummy_head;
        ListNode *tail = dummy_head;
    
        ListNode *ptr = head;
        int count = 0;
        while (ptr) {
            ListNode *curr = ptr;
            ptr = ptr->next;
            
            if (++count % 2) { // odd
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;
            } else { // even
                curr->next = prev->next;
                prev->next = curr;
                prev = tail;
            }
        }
        
        ListNode *result = dummy_head->next;
        delete dummy_head;
        return result;
    }
};
