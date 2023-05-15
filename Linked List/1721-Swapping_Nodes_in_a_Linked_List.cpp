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
    ListNode* swapNodes(ListNode* head,int k) 
    {
        ListNode *first=head,*second=head,*third=head;
        while(k--)
        {
            if(third==NULL)
            {
                return head;
            }
            if(k>0)
            {
                first=first->next;
            }
            third=third->next;
        }
        while(third!=NULL)
        {
            third=third->next;
            second=second->next;
        }
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        return head;
    }
};
