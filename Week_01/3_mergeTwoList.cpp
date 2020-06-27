/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /**
 思路:链表一般没什么花里胡哨的，纯指针操作，考查熟练度

 优化地方：if (current)，因为一开始不知道链表头。
 1、特化处理一次，先比较一次链表首元素，初始化current，后面在循环，这样能少个if分支判断
 2、看题解，可以使用一个虚拟链表头，最后在删除链表头。难怪ListNode给了构造函数，原来是暗示这么用的

 **/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = nullptr;
        ListNode* current = nullptr;
        while (l1 && l2)
        {
            ListNode *node = nullptr;
            if (l1->val > l2->val)
            {
                // node = new ListNode(l2);
                node = l2;
                l2 = l2->next;
            }
            else
            {
                node = l1;
                l1 = l1->next;
            }
            if (current)
            {
                current->next = node;current = node;
            }
            else
            {
                start = node; current=node;
            }
            
        }

        if (l1)
        {
            if (current)
            {
                current->next = l1;current = l1;
            }
            else
            {
                start = l1;
                current=l1;
            }
        }

        if (l2)
        {
            if (current)
            {
                current->next = l2;current = l2;
            }
            else
            {
                start = l2; current = l2;
            }
        }
        return start;
    }
};