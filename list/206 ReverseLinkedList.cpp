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

// 迭代
class Solution0 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *prev = nullptr, *cur = head;
        while(cur) {
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};
