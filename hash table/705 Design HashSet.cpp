//
//  705 Design HashSet.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>

#include "ListNode.h"
using namespace std;

// using STL
class MyHashSet1 {
public:
    /** Initialize your data structure here. */
    MyHashSet1() {
        key_range_ = 991;
        for (int i = 0; i < key_range_; ++i) {
            list<int> list;
            hash_set_.push_back(list);
        }
    }
    
    list<int> &hash_key_list(int key) {
        int index = key % key_range_;
        list<int> &list = hash_set_[index];
        return list;
    }
    
    void add(int key) {
        list<int> &list = hash_key_list(key);
        if (list.empty()) {
            list.push_back(key);
        } else {
            list.push_front(key);
        }
    }
    
    void remove(int key) {
        list<int> &list = hash_key_list(key);
        list.remove(key);
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        list<int> &list = hash_key_list(key);
        auto it = list.begin();
        for (; it != list.end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
private:
    int key_range_;
    vector<list<int> > hash_set_;
};

// ---------------------------------------------------------------------------------
// not using STL

class MyList {
public:
    /** Initialize your data structure here. */
    MyList() {
        dummy_node_ = new ListNode(-1);
    }
    
    int get_index(int val) {
        ListNode *curr = dummy_node_->next;
        int index = 0;
        while (curr) {
            if (curr->val == val) {
                return index;
            }
            index++;
            curr = curr->next;
        }
        return -1;
    }
    
    void add_at_head(int val) {
        ListNode *prev = dummy_node_;
        
        ListNode *newNode = new ListNode(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }
    
    void delete_element(int val) {
        
        ListNode *prev = dummy_node_;
        ListNode *curr = prev->next;
        while (curr) {
            if (curr->val == val) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            ListNode *deletedNode = curr;
            prev->next = prev->next->next;
            delete deletedNode;
        }
        
    }
    
private:
    ListNode *dummy_node_;
};

class Bucket {
private:
    MyList *container_;
    
public:
    Bucket() {
        container_ = new MyList();
    }
    
    void insert(int key) {
        int index = container_->get_index(key);
        if (index == -1) {
            container_->add_at_head(key);
        }
    }
    
    void remove(int key) {
        container_->delete_element(key);
    }
    
    bool exists(int key) {
        int index = container_->get_index(key);
        return (index != -1);
    }
};

class MyHashSet {
private:
    int key_range_;
    vector<Bucket> hash_set_;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        key_range_ = 991;
        for (int i = 0; i < key_range_; ++i) {
            Bucket bucket;
            hash_set_.push_back(bucket);
        }
    }
    
    Bucket &hash_key_list(int key) {
        int index = key % key_range_;
        return hash_set_[index];
    }
    
    void add(int key) {
        Bucket &bucket = hash_key_list(key);
        bucket.insert(key);
    }
    
    void remove(int key) {
        Bucket &bucket = hash_key_list(key);
        bucket.remove(key);
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        Bucket &bucket = hash_key_list(key);
        return bucket.exists(key);
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
