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
class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) 
    {
        ListNode node=ListNode(0,head);
        ListNode *p=&node,*m[2000001]={NULL};
        int pre=1000000;
        while(p)
        {
            pre+=(p->val);
            m[pre]=p;
            p=p->next;
        }
        pre=1000000,p=&node;
        while(p)
        {
            pre+=(p->val);
            p->next=m[pre]->next;
            p=p->next;
        }
        return node.next;
    }
};
