//
//  25 Reverse Nodes in k-Group.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *p = dummy;
        while (p) {
            ListNode *q = p;
            for (int i = 0; i < k && q; i++) {
                q = q->next;
            }
            
            if (!q) break;
            
            ListNode *a = p->next, *b = a->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode *c = b->next;
                b->next = a;
                a = b;
                b = c;
            }
            
            auto c = p->next;
            p->next = a;
            c->next = b;
            p = c;
        }
        
        return dummy->next;
    }
};
