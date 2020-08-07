//
//  Remove Nth Node From End of List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

/*
 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

 示例：
 给定一个链表: 1->2->3->4->5, 和 n = 2.
 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 
 说明：
 给定的 n 保证是有效的。

 进阶：
 你能尝试使用一趟扫描实现吗？
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        
        ListNode *new_node = new ListNode(-1);
        new_node->next = head;
        head = new_node;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (n--) fast = fast->next;
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *deleted_node = slow->next;
        slow->next = slow->next->next;
        
        delete deleted_node;

        head = head->next;
        delete new_node;
        
        return head;
    }
};
