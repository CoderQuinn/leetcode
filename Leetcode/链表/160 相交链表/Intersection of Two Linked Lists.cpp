//
//  Intersection of Two Linked Lists.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/11.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "ListNode.h"
#include <set>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/**
编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：

在节点 c1 开始相交。
 
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        /* 方法三：双指针法
         创建两个指针 pApA 和 pBpB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
         当 pApA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pBpB 到达链表的尾部时，将它重定位到链表 A 的头结点。
         若在某一时刻 pApA 和 pBpB 相遇，则 pApA/pBpB 为相交结点。
         想弄清楚为什么这样可行, 可以考虑以下两个链表: A={1,3,5,7,9,11} 和 B={2,4,9,11}，相交于结点 9。 由于 B.length (=4) < A.length (=6)，pBpB 比 pApA 少经过 22个结点，会先到达尾部。将 pBpB 重定向到 A 的头结点，pApA 重定向到 B 的头结点后，pBpB 要比 pApA 多走 2 个结点。因此，它们会同时到达交点。
         如果两个链表存在相交，它们末尾的结点必然相同。因此当 pApA/pBpB 到达链表结尾时，记录下链表 A/B 对应的元素。若最后元素不相同，则两个链表不相交。
         复杂度分析

         时间复杂度 : O(m+n)O(m+n)。
         空间复杂度 : O(1)O(1)。
         */
        
        if (!headA || !headB) {
            return nullptr;
        }
        
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        
        // 假设链表A的长度为m，链表B的长度为n
        while (nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            
            if (!nodeA && !nodeB) { // 两指针同时走完m+n后，仍不相交
                break;
            } else if (nodeA && !nodeB) { // m > n的情况，b先走完n
                nodeB = headA;
            } else if (nodeB && !nodeA) { // m < n的情况，a先走完m
                nodeA = headB;
            }

        }
        
        return nodeA;
    }
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
      /* 方法二: 哈希表法
       遍历链表 A 并将每个结点的地址/引用存储在哈希表中。然后检查链表 B 中的每一个结点 b是否在哈希表中。若在，则为相交结点。

        复杂度分析

        时间复杂度 : O(m+n)O(m+n)。
        空间复杂度 : O(m)O(m) 或 O(n)O(n)。
       */
        if (!headA || !headB) {
            return nullptr;
        }

        std::set<ListNode *> node_set;
        while (headB) {
            node_set.insert(headB);
            headB = headB->next;
        }

        while (headA) {
            if (node_set.find(headA) != node_set.end()) {
                return headA;
            }
            headA = headA->next;
        }

        return nullptr;
        
    }
};
