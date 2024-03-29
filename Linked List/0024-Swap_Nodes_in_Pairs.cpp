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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        else if(head->next== NULL)
        {
            return head;
        }
        ListNode *n=head->next;
        head->next=swapPairs(n->next);
        n->next=head;
        return n;
    }
};
