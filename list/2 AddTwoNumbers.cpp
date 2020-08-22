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
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *dummy_node = new ListNode(-1);
        ListNode *tail = dummy_node;
        
        int carry = 0;
        int sum = 0;
        while (l1 || l2)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            int val = (sum + carry) % 10;
            carry = (sum + carry) / 10;
            tail->next = new ListNode(val);
            tail = tail->next;
            sum = 0;
        }
        
        if (carry != 0)
        {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return dummy_node->next;
    }
};
