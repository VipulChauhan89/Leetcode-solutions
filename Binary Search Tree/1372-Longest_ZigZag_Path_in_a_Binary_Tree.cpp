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
    void dfs(TreeNode *root,bool left,int step,int &mx)
    {
        if(root==NULL)
        {
            return;
        }
        mx=max(mx,step);
        if(left)
        {
            dfs(root->left,false,step+1,mx);
            dfs(root->right,true,1,mx);
        }
        else
        {
            dfs(root->right,true,step+1,mx);
            dfs(root->left,false,1,mx);
        }
    }
    int longestZigZag(TreeNode* root) 
    {
        int mx=0;
        dfs(root,true,0,mx);
        dfs(root,false,0,mx);
        return mx;
    }
};
