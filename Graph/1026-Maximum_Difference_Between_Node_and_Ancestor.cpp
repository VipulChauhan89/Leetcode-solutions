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
    void dfs(TreeNode *root, int mn,int mx,int &diff)
    {
        if(root==NULL)
        {
            return;
        }
        diff=max(diff,max(abs(mx-root->val),abs(mn-root->val)));
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        dfs(root->left,mn,mx,diff);
        dfs(root->right,mn,mx,diff);
    
    }
    int maxAncestorDiff(TreeNode *root) 
    {
        int diff=0;
        dfs(root,root->val,root->val,diff);
        return diff;
    }
};
