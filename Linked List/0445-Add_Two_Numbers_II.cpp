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
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2) 
    {
        ListNode *ans=NULL;
        stack <int> s1,s2;
        int carry=0;
        while(l1!=NULL)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        while(!s1.empty() || !s2.empty())
        {
            int sum=(s1.empty()?0:s1.top())+(s2.empty()?0:s2.top())+carry;
            carry=sum>=10?1:0;
            ListNode *temp=new ListNode(sum%10);
            if(ans==NULL)
            {
                ans=temp;
            }
            else
            {
                temp->next=ans;
                ans=temp;
            }
            if(!s1.empty())
            {
                s1.pop();
            } 
            if(!s2.empty())
            {
                s2.pop();
            } 
        }
        if(carry==1)
        {
            ListNode *temp=new ListNode(carry);
            temp->next=ans;
            ans=temp;
        }
        return ans;
    }
};
