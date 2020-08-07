//
//  PalindromeLinkedList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <vector>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 思路1. 利用数组的特性：时间复杂度O(n)，空间复杂度O(n)
        std::vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < vec.size() / 2; ++i) {
            if (vec[i] != vec[vec.size() - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
};

class Solution1 {
public:
    bool isPalindrome(ListNode* head) {

        // 思路2：快慢指针
        if (!head) return true;
            
        ListNode *half_node = halfNodeOfList(head);
        ListNode *new_list = reverseList(half_node->next);
        
        ListNode *p = head;
        ListNode *q = new_list;
        bool result = true;
        while (q) {
            if (p->val != q->val) {
                result = false;
                break;
            }
            p = p->next;
            q = q->next;
        }
        
        half_node->next = reverseList(new_list);
    
        return result;
    }
    
private:
    
    ListNode *reverseList(ListNode* head) {
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
    
    ListNode *halfNodeOfList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
