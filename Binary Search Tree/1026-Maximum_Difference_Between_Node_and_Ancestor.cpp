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
    int ans(TreeNode * root,int mn,int mx)
    {
        if(root==NULL)
        {
            return mx-mn;
        }
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        return max(ans(root->left,mn,mx),ans(root->right,mn,mx));
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        return ans(root,INT_MAX,INT_MIN);
    }
};
