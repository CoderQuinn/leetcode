//
//  Reverse Linked List II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        auto a = dummy;
        for(int i = 1; i < m; i++)
            a = a->next;
        auto b = a->next, c = b->next;
        for(int i = 0; i < n - m; i++)
        {
            auto tmp = c ->next;
            c->next = b;
            b = c;
            c = tmp;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};
