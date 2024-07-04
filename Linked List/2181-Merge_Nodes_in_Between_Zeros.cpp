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
    ListNode* mergeNodes(ListNode *head) 
    {
        ListNode *modify=head->next,*next=head->next;
        while(next!=NULL)
        {
            int sum=0;
            while(next->val!=0)
            {
                sum+=next->val;
                next=next->next;
            }
            modify->val=sum;
            next=next->next;
            modify->next=next;
            modify=modify->next;
        }
        return head->next;
    }
};
