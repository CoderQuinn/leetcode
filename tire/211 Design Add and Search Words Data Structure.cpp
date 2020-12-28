//
//  211 Design Add and Search Words Data Structure.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class WordDictionary
{
public:
    struct Node
    {
        Node *son[26];
        bool is_end;
        Node()
        {
            is_end = false;
            for (int i = 0; i < 26; i++)
            {
                son[i] = nullptr;
            }
        }
    };
    
    /** Initialize your data structure here. */
    Node *root;
    WordDictionary()
    {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        auto p = root;
        for (auto &c : word)
        {
            int u = c - 'a';
            if (!p->son[u])
            {
                p->son[u] = new Node();
            }
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return dfs(root, word, 0);
    }
    
    bool dfs(Node *p, string &word, int u)
    {
        if (u == word.size())
        {
            return p->is_end;
        }
        if (word[u] != '.')
        {
            int i = word[u] - 'a';
            if (!p->son[i])
                return false;
            return dfs(p->son[i], word, u + 1);
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (p->son[i] && dfs(p->son[i], word, u + 1))
                {
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
