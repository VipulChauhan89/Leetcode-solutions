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
    vector<ListNode*> splitListToParts(ListNode *head,int k) 
    {
        vector<ListNode*> ans(k);
        int n=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        auto [q,r]=div(n,k);
        vector<int> len(k,q);
        fill(len.begin(),len.begin()+r,q+1);
        temp=head;
        for(int i=0;i<k;i++)
        {
            ans[i]=temp;
            for(int j=0;j<len[i]-1;j++)
            {
                temp=temp->next;
            }
            if(temp)
            {
                ListNode *prev=temp;
                temp=temp->next;
                prev->next=NULL;
            }
        }
        return ans;
    }
};
