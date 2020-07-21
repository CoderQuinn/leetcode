//
//  ReverseLinkedList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/11.
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

//反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 使用头插法的思路解决
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *temp = curr;
            curr = curr->next;
            
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
};
