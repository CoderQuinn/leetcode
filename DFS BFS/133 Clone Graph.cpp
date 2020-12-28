//
//  133 Clone Graph.cpp
//  Leetcode
//
//  Created by Quinn on 2020/11/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> hash;

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        dfs(node); // 复制所有点

        for (auto [v, s] : hash) // 复制所有边
        {
            for (auto ver : v->neighbors)
            {
                s->neighbors.push_back(hash[ver]);
            }
        }

        return hash[node];
    }

    void dfs(Node *u)
    {
        if (!u)
            return;
        hash[u] = new Node(u->val);

        for (auto ver : u->neighbors)
        {
            if (!hash.count(ver))
                dfs(ver);
        }
    }
};
