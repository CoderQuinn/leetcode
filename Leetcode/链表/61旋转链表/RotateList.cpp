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
        if (!head || !head->next) return head; // 空链表和只有一个节点的链表
        
        int len = 1;
        ListNode *curr = head;
        while (curr->next) {
            curr = curr->next;
            ++len;
        }
        
        curr->next = head; // 形成环
        
        int step = len - k % len - 1;
        curr = head;
        while (step-- > 0) {
            curr = curr->next;
        }
        
        ListNode *new_head = curr->next;
        curr->next = nullptr; // 打破环
        
        return new_head;
    }
};
