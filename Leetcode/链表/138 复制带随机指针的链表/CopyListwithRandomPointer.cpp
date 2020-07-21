//
//  CopyListwithRandomPointer.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <map>

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
        
        std::map<Node*, Node*> visited_map;
        std::map<Node*, Node*> &map = visited_map;
        
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
    Node *cloneNode(Node *node, std::map<Node*, Node*> &map)
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
class Solution02 {
    std::map<Node*, Node*> visited_map;
    
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // 该节点是否被处理过
        if (visited_map.count(head)) return visited_map[head];

        Node *new_head = new Node(head->val);
        
        visited_map[head] = new_head;
        
        new_head->next = copyRandomList(head->next);
        new_head->random = copyRandomList(head->random);
        
        return new_head;

    }
    
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node *p = head;
        while (p) {
            Node *add_node = new Node(p->val);
            
            add_node->next = p->next;
            p->next = add_node;
            
            p = add_node->next;
        }
        
        p = head;
        
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            } else {
                p->next->random = nullptr;
            }
    
            p = p->next->next;
        }
        
        Node *old_ptr = head;
        Node *new_ptr = head->next;
        Node *result = head->next;
        
        while (old_ptr) {
            old_ptr->next = old_ptr->next->next;
            if (new_ptr->next) { // 最后一个结点的情况:d->d'->null
                new_ptr->next = new_ptr->next->next;
            } else {
                new_ptr->next = nullptr;
            }
            
            
            old_ptr = old_ptr->next;
            new_ptr = new_ptr->next;
        }
        
        return result;
    }
};
