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

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};

