//
//  OddEvenLinkedList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 利用链表尾插法的思想
        if (!head) return nullptr;
        
        ListNode *odd_head = head;
        ListNode *odd_tail = odd_head;
        head = head->next;
        
        ListNode even_head(-1);
        ListNode *even_tail = &even_head;
        
        int i = 1;
        while (head) {
            ListNode *curr = head;
            if (++i % 2) { // 奇数节点
                odd_tail->next = curr;
                odd_tail = curr;
            } else { // 偶数节点
                even_tail->next = curr;
                even_tail = curr;
            }
            head = head->next;
            curr->next = nullptr;
        }
        odd_tail->next = even_head.next;
      
        return odd_head;
    }
};
