//
//  DesignLinkedList.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/13.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"

class MyList {
public:
        /** Initialize your data structure here. */
        MyList(): size_(0) {
            dummy_node_ = new MapNode(-1);
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            if (index < 0 || index >= size_) {
                return -1;
            }

            MapNode *curr = dummy_node_;
            for (int i = 0; i < index + 1; ++i) {
                curr = curr->next;
            }
            return curr->val;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            addAtIndex(0, val);
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            addAtIndex(size_, val);
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            if (index > size_) return;

            if(index < 0) index = 0;

            MapNode *prev = dummy_node_;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }

            MapNode *newNode = new MapNode(val);
            newNode->next = prev->next;
            prev->next = newNode;

            size_++;
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            if (index < 0 || index >= size_) return;

            MapNode *prev = dummy_node_;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }

            MapNode *deletedNode = prev->next;
            prev->next = prev->next->next;

            delete deletedNode;
            
            --size_;
        }

private:
        // Definition for singly-linked list.
        struct MapNode {
            int val;
            MapNode *next;
            MapNode(int x) : val(x), next(NULL) {}
        };
        MapNode *dummy_node_; // 哑结点
        int size_; // 链表的长度
};

class MyLinkedList1 {
public:
    /** Initialize your data structure here. */
    MyLinkedList1() {
        size = 0;
        dummy_head = new DoublyListNode(0);
        dummy_tail = new DoublyListNode(0);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        DoublyListNode *curr = nullptr;
        if (index + 1  < size - index) {
            curr = dummy_head;
            for (int i = 0; i < index + 1; ++i) {
                curr = curr->next;
            }

        } else {
           curr = dummy_tail;
            for (int i = 0; i < size - index; ++i) {
                curr = curr->prev;
            }
        }

        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        DoublyListNode *pred = dummy_head; // Predecessor
        DoublyListNode *succ = dummy_head->next; // Successor

        DoublyListNode *add_node = new DoublyListNode(val);

        add_node->next = succ;
        add_node->prev = pred;
        succ->prev = add_node;
        pred->next = add_node;

        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        DoublyListNode *pred = dummy_tail->prev; // Predecessor
        DoublyListNode *succ = dummy_tail; // Successor

        DoublyListNode *add_node = new DoublyListNode(val);

        add_node->next = succ;
        add_node->prev = pred;
        succ->prev = add_node;
        pred->next = add_node;

        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;

        if(index < 0) index = 0;

        DoublyListNode *curr = nullptr;
        if (index + 1  < size - index) {
            curr = dummy_head;
            for (int i = 0; i < index + 1; ++i) {
                curr = curr->next;
            }

        } else {
           curr = dummy_tail;
            for (int i = 0; i < size - index; ++i) {
                curr = curr->prev;
            }
        }

        DoublyListNode *pred = curr->prev; // Predecessor
        DoublyListNode *succ = curr; // Successor

        DoublyListNode *add_node = new DoublyListNode(val);

        add_node->next = succ;
        add_node->prev = pred;
        succ->prev = add_node;
        pred->next = add_node;

        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        DoublyListNode *curr = nullptr;
        if (index + 1  < size - index) {
            curr = dummy_head;
            for (int i = 0; i < index + 1; ++i) {
                curr = curr->next;
            }

        } else {
           curr = dummy_tail;
            for (int i = 0; i < size - index; ++i) {
                curr = curr->prev;
            }
        }

        DoublyListNode *deletedNode = curr;
        DoublyListNode *pred = curr->prev; // Predecessor
        DoublyListNode *succ = curr->next; // Successor

        succ->prev = pred;
        pred->next = succ;

        delete deletedNode;

        --size;
    }

private:
    // Definition for doubly-linked list.
    struct DoublyListNode {
        int val;
        DoublyListNode *next, *prev;
        DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
    };
    DoublyListNode *dummy_head; // 哑头结点
    DoublyListNode *dummy_tail; // 哑尾结点

    int size; // 链表的长度

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
