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
    void dfs(TreeNode *root,int cd,int &mxD,int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(cd>mxD)
        {
            ans=root->val;
            mxD=cd;
        }
        dfs(root->left,cd+1,mxD,ans);
        dfs(root->right,cd+1,mxD,ans);
    }
    int findBottomLeftValue(TreeNode *root) 
    {
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        int ans=0,cd=1,mxD=0;
        dfs(root,cd,mxD,ans);
        return ans;
    }
};
