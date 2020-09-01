//
//  208 Implement Trie (Prefix Tree).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <string>
using namespace std;

class Trie {
    // change this value to adapt to different cases
#define N 26
    
    struct TrieNode {
        TrieNode *children[N];
        bool is_end;
        TrieNode() {
            is_end = false;
            for (int i = 0; i < N; ++i) {
                children[i] = nullptr;
            }
        }
        // you might need some extra values according to different cases
    };
    
    /** Usage:
     *  Initialization: TrieNode root = new TrieNode();
     *  Return a specific child node with char c: (root->children)[c - 'a']
     */
    
public:
    TrieNode *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!curr->children[i]) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->is_end = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return curr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (auto c : prefix) {
            int i = c - 'a';
            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
