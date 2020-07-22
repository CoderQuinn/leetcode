//
//  Reverse Linked List II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int length = n - m + 1;
        ListNode *prev = nullptr; // 指向逆置后头结点的前驱
        ListNode *result = head; // 转换后的链表头结点
        while (head && --m > 0) { // 链表head前移m-1个位置
            prev = head;
            head = head->next;
        }
        ListNode *change_tial = head; // 指向逆置后的尾结点
        ListNode *new_head = nullptr;
        
        while (head && length-- > 0) {
            ListNode *curr = head;
            head = head->next;
            curr->next = new_head;
            new_head = curr;
        }
        change_tial->next = head; // 链接剩下的尾部
        if (!prev) { // m = 1的情况
            result = new_head;
        } else {
            prev->next = new_head;
        }
        
        return result;
    }
};
