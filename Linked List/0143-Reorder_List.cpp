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
    void reorderList(ListNode *head) 
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return;
        }
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next) 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=NULL,*cur=slow->next,*Next;
        while(cur) 
        {
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
        slow->next=NULL;
        ListNode *A=head,*B=prev;
        while(A && B) 
        {
            ListNode *A_next=A->next,*B_next=B->next;
            A->next=B;
            B->next=A_next;
            A=A_next;
            B=B_next;
        }
    }
};
