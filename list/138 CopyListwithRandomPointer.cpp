//
//  Copy List with Random Pointer.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
 提示：
 
 -10000 <= Node.val <= 10000
 Node.random 为空（null）或指向链表中的节点。
 节点数目不超过 1000 。
 */

// 思路1：迭代的思路，空间复杂度O(n)，时间复杂度O(n)
class Solution01 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        map<Node*, Node*> visited_map;
        map<Node*, Node*> &map = visited_map;
        
        Node *reslut = new Node(head->val);
        Node *old_node = head;
        Node *new_node = reslut;
        visited_map[old_node] = new_node;
        
        while (old_node) {
            
            new_node->next = cloneNode(old_node->next,map);
            new_node->random = cloneNode(old_node->random, map);
            
            old_node = old_node->next;
            new_node = new_node->next;
        }
        
        
        return reslut;
    }
    
private:
    Node *cloneNode(Node *node, map<Node*, Node*> &map)
    {
        if (!node) return nullptr;
        
        if (!map.count(node)) {
            Node *add_node = new Node(node->val);
            map[node] = add_node;
        }
        return map[node];
    }
};

// 思路2：递归的思路：空间复杂度O(n)，时间复杂度O(n)
class Solution1 {
public:
    unordered_map<Node *, Node *> hash;
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }
        if(hash.count(head))
            return hash[head];
        
        Node *ans = new Node(head->val);
        hash[head] = ans;
        
        ans->next = copyRandomList(head->next);
        ans->random = copyRandomList(head->random);
        
        return ans;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        for(auto p = head; p; p = p->next->next) {
            Node *q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }
        
        for(auto p = head; p; p = p->next->next) {
            if(p->random) {
                p->next->random = p->random->next;
            }
        }
        Node *dummy = new Node(-1), *curr = dummy;
        for(auto p = head; p; p = p->next) {
            auto q = p->next;
            curr->next = q;
            curr = curr->next;
            p->next = q->next;
        }
        return dummy->next;
    }
};
