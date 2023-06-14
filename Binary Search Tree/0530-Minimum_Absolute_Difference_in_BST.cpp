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
    TreeNode *prev=NULL;
    int dif=INT_MAX;
    void dfs(TreeNode *root)
    {
        if(root->left)
        {
            dfs(root->left);   
        }
        if(prev)
        {
            dif=min(dif,abs(prev->val - root->val));
        }
        prev=root;
        if(root->right)
        {
            dfs(root->right);
        }
    }
    int getMinimumDifference(TreeNode *root) 
    {
        dfs(root);
        return dif;
    }
};
