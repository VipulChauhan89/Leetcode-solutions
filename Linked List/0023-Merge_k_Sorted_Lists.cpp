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
    ListNode* mergeTwoSorted(ListNode *l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* last=dummy;
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                last->next=l1;
                last=l1;
                l1=l1->next;
            }
            else
            {
                last->next=l2;
                last=l2;
                l2=l2->next;
            }
        }
        if(!l1)
        {
            last->next = l2;
        }
        else
        {
            last->next = l1;
        }
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n=lists.size();
        if(lists.size()==0)
        {
            return NULL;
        } 
        while(n>1)
        {
            for(int i=0;i<n/2;i++)
            {
                lists[i]=mergeTwoSorted(lists[i],lists[n-i-1]);
            }
            n=(n+1)/2;
        }
        return lists.front();
    }
};
