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
    vector<vector<int>> spiralMatrix(int m,int n,ListNode *head) 
    {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int l=0,r=n,u=0,d=m;
        while(head!=NULL) 
        {
            for(int i=l;i<r && head!=NULL;i++) 
            {
                ans[u][i]=head->val;
                head=head->next;
            }
            u++;
            for(int i=u;i<d && head!=NULL;i++) 
            {
                ans[i][r-1]=head->val;
                head=head->next;
            }
            r--;
            for(int i=r-1;i>=l && head!=NULL;i--) 
            {
                ans[d-1][i]=head->val;
                head=head->next;
            }
            d--;
            for(int i=d-1;i>=u && head!=NULL;i--) 
            {
                ans[i][l]=head->val;
                head=head->next;
            }
            l++;
        }
        return ans;
    }
};
