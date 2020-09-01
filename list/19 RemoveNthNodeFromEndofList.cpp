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
        if(!head) return nullptr;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        
        for(int i = 0; i < n; i++)
        {
            if(fast) fast = fast->next;
            else return nullptr;
        }

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};
