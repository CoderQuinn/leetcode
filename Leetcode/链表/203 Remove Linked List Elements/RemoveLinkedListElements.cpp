//
//  RemoveLinkedListElements.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode node(-1);
        node.next = head;
        head = &node;
        
        ListNode *curr = head->next;
        ListNode *prev = head;
        
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            
            curr = curr->next;
        }
        
        head = head->next;

        return head;
    }
};
