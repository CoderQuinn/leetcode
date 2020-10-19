//
//  82 Remove Duplicates from Sorted List II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/11.
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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next)
        {
            auto q = p->next;
            while(q && p->next->val == q->val)
                q = q->next;
            
            if(p->next->next == q)
                p = p->next;
            else
                p->next = q;
        }
        return dummy->next;
    }
};
