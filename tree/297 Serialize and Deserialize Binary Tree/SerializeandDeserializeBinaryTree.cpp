//
//  SerializeandDeserializeBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/29.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <string>
#include <queue>
using namespace::std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 层次遍历迭代
class Codec {
public:
    // Encodes a tree to a single string.
    const string NULL_STR = "null";
    const char *SEPTARTER_STR = ",";
    string serialize(TreeNode *root) {
        std::string data;
        if (!root) return data;
        
        std::queue<TreeNode *> node_quque;
        TreeNode *curr = root;
        data += std::to_string(curr->val);
        data += SEPTARTER_STR;
        
        node_quque.push(curr);
        while (!node_quque.empty()) {
            auto size = node_quque.size();
            
            while (size > 0) {
                curr = node_quque.front();
                node_quque.pop();
                
                if (curr->left) {
                    data += std::to_string(curr->left->val);
                    data += SEPTARTER_STR;
                    node_quque.push(curr->left);
                } else {
                    data += NULL_STR;
                    data += SEPTARTER_STR;
                }
                
                if (curr->right) {
                    data += std::to_string(curr->right->val);
                    data += SEPTARTER_STR;
                    node_quque.push(curr->right);
                } else {
                    data += NULL_STR;
                    data += SEPTARTER_STR;
                }
                
                --size;
            }
            
        }
        return data;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        if (data.empty()) return root;
        
        vector<string> node_vec = split(data, SEPTARTER_STR);
        
        
        int val = std::stoi(node_vec[0]);
        root = new TreeNode(val);

        std::queue<TreeNode *> node_quque;
   
        TreeNode *curr = root;
        node_quque.push(curr);
        
        int i = 1;
        while (!node_quque.empty()) {
            auto size = node_quque.size();
            
            while (size > 0) {
                curr = node_quque.front();
                node_quque.pop();
                
                if (node_vec[i] != NULL_STR) {
                    int val = std::atoi(node_vec[i].c_str());
                    curr->left = new TreeNode(val);
                    node_quque.push(curr->left);
                }
                i++;
                
                if (node_vec[i] != NULL_STR) {
                    int val = std::atoi(node_vec[i].c_str());
                    curr->right = new TreeNode(val);
                    node_quque.push(curr->right);
                }
                i++;
                
                --size;
            }
            
        }
        
        
        return root;
    }
    
    vector<string> split(string &s, const char *delim)
    {
        vector<string> vector;
        
        char *str = strtok((char*)s.c_str(), delim);
        while (str)
        {
            vector.push_back(string(str));
            str = strtok(nullptr, delim);
        }
        return vector;
    }
};

// 前序遍历，递归
class Codec1 {
public:
    const string NULL_STR = "null";
    const char *SEPTARTER_STR = ",";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return NULL_STR + SEPTARTER_STR;

        string s = to_string(root->val);
        s += SEPTARTER_STR;
        s += serialize(root->left);
        s += serialize(root->right);
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> data_vec = split(data, SEPTARTER_STR);
        int index = 0;
        return deserialize_core(data_vec, index);
    }
    
    TreeNode* deserialize_core(vector<string> &data_vec, int &index) {
        string curr_str = data_vec[index];
        if (curr_str == NULL_STR) return nullptr;
        
        TreeNode *root = new TreeNode(stoi(curr_str));
        root->left = deserialize_core(data_vec, ++index);
        root->right = deserialize_core(data_vec, ++index);

        return root;
    }
    
    vector<string> split(string &s, const char *delim)
    {
        vector<string> vector;
        
        char *str = strtok((char*)s.c_str(), delim);
        while (str)
        {
            vector.push_back(string(str));
            str = strtok(nullptr, delim);
        }
        return vector;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
