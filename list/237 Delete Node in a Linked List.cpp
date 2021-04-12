//
//  237 Delete Node in a Linked List.cpp
//  Leetcode
//
//  Created by Quinn on 2021/1/2.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include "ListNode.h"

class Solution0 {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
