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
    ListNode* modifiedList(vector<int> &nums,ListNode *head) 
    {
        unordered_set<int> s;
        for(auto i:nums)
        {
            s.insert(i);
        }
        ListNode *temp=new ListNode();
        temp->next=head;
        ListNode *current=temp,*previous=temp;
        while(current!=NULL)
        {
            if(s.count(current->val)!=0)
            {
                previous->next=current->next;
            }
            else
            {
                previous=current;
            }
            current=current->next;
        }
        return temp->next;
    }
};
