//
//  AddTwoNumbers.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/14.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummy_head;
        int carry = 0;
        
        while (p || q) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            
            ListNode *add_node = new ListNode(sum % 10);
            curr->next = add_node;
            curr = add_node;

            // 指针向高位移动，直到最长链表的当前指针为空
            if (p) {
                p = p->next;
            }
            
            if (q) {
                q = q->next;
            }
        }

        if (carry != 0) {
            ListNode *add_node = new ListNode(carry);
            curr->next = add_node;
        }
        curr = dummy_head->next;
        delete dummy_head;
        
        return curr;
    }
};
