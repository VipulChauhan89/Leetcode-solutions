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
class Solution {
public:
    int modifiedDfs(TreeNode *root,int start,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=modifiedDfs(root->left,start,ans);
        int right=modifiedDfs(root->right,start,ans);
        int depth=0;
        if(root->val==start)
        {
            ans=max(left,right);
            depth=-1;
        }
        else if(left>=0 && right>=0)
        {
            depth=max(left,right)+1;
        }
        else
        {
            int distance=abs(left)+abs(right);
            ans=max(ans,distance);
            depth=min(left,right)-1;
        }
        return depth;
    }
    int amountOfTime(TreeNode *root,int start) 
    {
        int ans=0;
        modifiedDfs(root,start,ans);
        return ans;
    }
};
