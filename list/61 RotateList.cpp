//
//  RotateList.cpp
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 0;
        ListNode *p = nullptr;
        ListNode *curr = head;
        while(curr)
        {
            p = curr;
            curr = curr->next;
            n++;
        }
        
        p->next = head; // 形成环
        k %= n;
        
        curr = head;
        for(int i = 0; i < n - k - 1; i++)
        {
            curr = curr->next;
        }
        
        p = curr->next;
        curr->next = nullptr; // 打破环
        return p;
    }
};
