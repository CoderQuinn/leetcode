//
//  Remove Duplicates from Sorted List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/17.
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
        if (!head) return nullptr;
    
        ListNode *curr = head;
        
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode *deleted = curr->next;
                curr->next = curr->next->next;
                delete deleted;
            } else {
                curr = curr->next;
            }
            
        }
        
        return head;
    }
};
