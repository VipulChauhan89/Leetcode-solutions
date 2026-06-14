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
        ListNode *slow=head,*fast=head,*prev=nullptr;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            swap(slow->next,prev);
            swap(prev,slow);
        }
        int ans=0;
        while(slow)
        {
            ans=max(ans,prev->val+slow->val);
            prev=prev->next;
            slow=slow->next;
        }
        return ans;
    }
};
