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
    vector<int> nodesBetweenCriticalPoints(ListNode *head) 
    {
        int i=0,size=0,p0=-1,p1=-1,minD=INT_MAX;
        int x0=head->val,x1=head->next->val;
        bool less=x1<x0,bigger=x1>x0;
        for(ListNode *next=head->next->next;next;i++,next=next->next)
        {
            int x=next->val;
            bool bigger1=x>x1,less1=x<x1;
            if((less && bigger1)||(bigger && less1))
            {
                if(size==0)
                {
                    p0=i;
                }
                size++;
                if(p1!=-1)
                {
                    minD=min(i-p1,minD);
                }
                p1=i;
            }
            bigger=bigger1;
            less=less1;
            x1=x;
        }
        if(size<=1)
        {
            return {-1,-1};
        }
        else
        {
            return {minD,p1-p0};
        }
    }
};
