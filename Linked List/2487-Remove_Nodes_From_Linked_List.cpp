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
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode *ans=head,*next=NULL;;
        stack<ListNode*> st;
        while(ans!=nullptr) 
        {
            while(!st.empty() && st.top()->val<ans->val) 
            {
                st.pop();
            }
            st.push(ans);
            ans=ans->next;
        }
        while(!st.empty()) 
        {
            ans=st.top();
            st.pop();
            ans->next=next;
            next=ans;
        }
        return ans; 
    }
};
