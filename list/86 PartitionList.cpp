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
        
        ListNode *l_dummy = new ListNode(-1);
        ListNode *r_dummy = new ListNode(-1);
        ListNode *lt = l_dummy;
        ListNode *rt = r_dummy;
        for (auto p = head; p; p = p->next) {
            if(p->val < x)
            {
                lt->next = p;
                lt = lt->next;
            }
            else
            {
                rt->next = p;
                rt = rt->next;
            }
        }
        lt->next = r_dummy->next;
        rt->next = nullptr;
        
        return l_dummy->next;
    }
};
