//
//  AddTwoNumbers.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <stack>
using namespace::std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr = l1;
        while (curr) {
            stack1.push(curr);
            curr = curr->next;
        }
        
        curr = l2;
        while (curr) {
            stack2.push(curr);
            curr = curr->next;
        }
        
        ListNode *dummy_node = new ListNode(-1);
        ListNode *head = dummy_node;
        int carry = 0;
        while (!stack1.empty() || !stack2.empty()) {
            int x = stack1.empty() ? 0 : stack1.top()->val;
            int y = stack2.empty() ? 0 : stack2.top()->val;
            if (!stack1.empty()) stack1.pop();
            if (!stack2.empty()) stack2.pop();
            
            int sum = x + y + carry;
            carry = sum / 10;
            ListNode *add_node = new ListNode(sum % 10);
            add_node->next = head->next;
            head->next = add_node;
            
        }
        
        if (carry != 0) {
            ListNode *add_node = new ListNode(carry);
            add_node->next = head->next;
            head->next = add_node;
        }
        
        head = dummy_node->next;
        dummy_node->next = nullptr;
        delete dummy_node;
        
        return head;
    }
private:
    std::stack<ListNode *> stack1;
    std::stack<ListNode *> stack2;
};
