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
    int pairSum(ListNode* head) 
    {
        ListNode *slow=head,*fast=head;
        stack<int> st;
        while(fast)
        {
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        int mx=0;
        while(slow)
        {
            mx=max(mx,st.top()+slow->val);
            slow=slow->next;
            st.pop();
        }
        return mx;
    }
};
