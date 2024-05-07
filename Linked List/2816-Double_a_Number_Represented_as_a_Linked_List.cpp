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
    ListNode* doubleIt(ListNode *head) 
    {
        int value=0;
        stack<int> st;
        ListNode *ans=NULL;
        while(head!=NULL)
        {
            st.push(head->val);
            head=head->next;
        }    
        while(!st.empty() || value!=0)
        {
            ans=new ListNode(0,ans);
            if(!st.empty())
            {
                value+=st.top()*2;
                st.pop();
            }
            ans->val=value%10;
            value/=10;
        }
        return ans;
    }
};
