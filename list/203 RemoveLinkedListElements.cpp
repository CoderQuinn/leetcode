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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        for(auto p = dummy; p; p = p->next) {
            auto q = p->next;
            while(q && q->val == val) q = q->next;
            p->next = q;
        }
        
        return dummy->next;
    }
};
