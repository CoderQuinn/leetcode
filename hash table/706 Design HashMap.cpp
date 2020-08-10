//
//  706 Design HashMap.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

// using STL
class MyHashMap1 {
public:
    /** Initialize your data structure here. */
    MyHashMap1() {
        key_range_ = 2011;
        for (int i = 0; i < key_range_; ++i) {
            list<pair<int, int>> list;
            hash_map_.push_back(list);
        }
    }
    
    list<pair<int, int>> &hash_key_list(int key) {
        int index = key % key_range_;
        return hash_map_[index];
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        list<pair<int, int>> &list = hash_key_list(key);
        auto it = get_iterator_of(key, list);
        if (it != list.end()) {
            return it->second;
        }
        return -1;
    }
    
    list<pair<int, int>>::iterator get_iterator_of(int key, list<pair<int, int>> &list) {
        auto it = list.begin();
        while (it != list.end()) {
            if (it->first == key) {
                return it;
            }
            ++it;
        }
        return list.end();
    }
    
    
    void put(int key, int value) {
        list<pair<int, int>> &list = hash_key_list(key);
        auto it = get_iterator_of(key, list);
        if (it != list.end()) {
            it->second = value;
        } else {
            list.push_front(make_pair(key, value));
        }
    }
    
    void remove(int key) {
        list<pair<int, int>> &list = hash_key_list(key);
        auto it = get_iterator_of(key, list);
        if (it != list.end()) {
            list.erase(it);
        }
    }
    
private:
    int key_range_;
    vector<list<pair<int, int>> > hash_map_;
};

// not using STL
struct MyNode {
    int key;
    int val;
    MyNode *next;
    MyNode(int key, int val) :  key(key), val(val), next(NULL) {}
};

class MyList {
public:
    /** Initialize your data structure here. */
    MyList() {
        dummy_node_ = new MyNode(-1, -1);
    }
    
    MyNode *get_node(int key) {
        MyNode *curr = dummy_node_->next;
        while (curr) {
            if (curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }
    
    void add_at_head(int key, int val) {
        MyNode *prev = dummy_node_;
        
        MyNode *newNode = new MyNode(key, val);
        newNode->next = prev->next;
        prev->next = newNode;
    }
    
    void delete_element(int key) {
        
        MyNode *prev = dummy_node_;
        MyNode *curr = prev->next;
        while (curr) {
            if (curr->key == key) {
                prev->next = prev->next->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
private:
    MyNode *dummy_node_;
};

class Bucket {
private:
    MyList *container_;
    
public:
    Bucket() {
        container_ = new MyList();
    }
    
    void remove(int key) {
        container_->delete_element(key);
    }
    
    void put(int key, int value) {
        MyNode *node = container_->get_node(key);
        if (node) {
            node->val = value;
        } else {
            container_->add_at_head(key, value);
        }
    }
    
    int get(int key) {
        MyNode *node = container_->get_node(key);
        if (node) {
            return node->val;
        }
        return -1;
    }
};

class MyHashMap {
private:
    int key_range_;
    vector<Bucket> hash_set_;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
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
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        Bucket &bucket = hash_key_list(key);
        bucket.put(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        Bucket &bucket = hash_key_list(key);
        return bucket.get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Bucket &bucket = hash_key_list(key);
        bucket.remove(key);
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
