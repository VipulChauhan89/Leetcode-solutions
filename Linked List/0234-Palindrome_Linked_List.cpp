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
    ListNode *f;
    bool check(ListNode *n)
    {
        if(n!=NULL)
        {
            if(!check(n->next))
            {
                return 0;
            }
            if(n->val!=f->val)
            {
                return 0;
            }
            f=f->next;
        }
        return 1;
    }
    bool isPalindrome(ListNode *head) 
    {
        f=head;
        return check(head);
    }
};
