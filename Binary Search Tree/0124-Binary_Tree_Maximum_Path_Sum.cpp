/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int subTreesum(TreeNode* r,int& mx)
    {
        if(r==NULL) 
        {
            return 0;
        }
        int l=max(0,subTreesum(r->left,mx));
        int h=max(0,subTreesum(r->right,mx));
        int curr=r->val+l+h;
        mx=max(mx,curr);                                    
        return r->val+max(l,h);       
    }
    int maxPathSum(TreeNode* root) 
    {
        int mx=INT_MIN;
        subTreesum(root,mx);
        return mx;
    }
};
