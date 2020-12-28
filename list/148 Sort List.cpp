//
//  148 Sort List.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for(int i = 1; i < n; i *= 2) {
            auto cur = dummy;
            for(int j = 1; j <= n; j += 2 * i) {
                auto p = head, q = p;
                for(int k = 0; k < i && q; k++)
                    q = q->next;
                int l = 0, r = 0;
                while(l < i && r < i && p && q) {
                    if(p->val <= q->val) {
                        cur->next = p;
                        cur = cur->next;
                        p = p->next;
                        l++;
                    } else {
                        cur->next = q;
                        cur = cur->next;
                        q = q->next;
                        r++;
                    }
                }
                
                while(l < i && p) {
                    cur->next = p;
                    cur = cur->next;
                    p = p->next;
                    l++;
                }
                
                while(r < i && q) {
                    cur->next = q;
                    cur = cur->next;
                    q = q->next;
                    r++;
                }
                head = q;
            }
            cur->next = nullptr;
            head = dummy->next;
        }
        
        return dummy->next;
    }
};
