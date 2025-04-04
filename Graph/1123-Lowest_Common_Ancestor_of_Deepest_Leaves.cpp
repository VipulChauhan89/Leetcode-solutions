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
    TreeNode *dfs(TreeNode *root,int mx,int length)
    {
        if(!root)
        {
            return NULL;
        }
        if(mx-1==length)
        {
            return root;
        }
        TreeNode *left=dfs(root->left,mx,length+1),*right=dfs(root->right,mx,length+1);
        if(left && right)
        {
            return root;
        }
        return left?left:right;
    }
    int mxDepth(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+max(mxDepth(root->left),mxDepth(root->right));
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root) 
    {
        int mx=mxDepth(root);
        return dfs(root,mx,0);
    }
};
