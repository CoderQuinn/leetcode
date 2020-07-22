//
//  Merge Two Sorted Lists.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/14.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy_node(0);
        ListNode *tail = &dummy_node;
    
        while (l1 && l2) {
            ListNode *add_node = nullptr;
            
            if (l1->val < l2->val) {
                add_node = l1;
                l1 = l1->next;
            } else {
                add_node = l2;
                l2 = l2->next;
            }
            
            tail->next = add_node;
            tail = add_node;
        }
        tail->next = l1 ? l1 : l2;
        
        return dummy_node.next;
    }
};
