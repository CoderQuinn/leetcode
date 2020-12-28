//
//  147 Insertion Sort List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/9.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        
        for (auto p = head; p; ) {
            auto cur = dummy, tmp = p->next;
            while (cur->next && cur->next->val <= p->val) {
                cur = cur->next;
            }
            p->next = cur->next;
            cur->next = p;
            p = tmp;
        }
        
        return dummy->next;
    }
};
