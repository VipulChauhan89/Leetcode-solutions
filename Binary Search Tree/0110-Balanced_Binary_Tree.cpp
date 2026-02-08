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
    int dfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftheight=dfs(root->left);
        if(leftheight==-1)
        {
            return -1;
        }
        int rightheight=dfs(root->right);
        if(rightheight==-1)
        {
            return -1;
        }
        if(abs(leftheight-rightheight)>1)
        {
            return -1;
        }
        return max(leftheight,rightheight)+1;
    }

    bool isBalanced(TreeNode *root)
    {
        return dfs(root)!=-1;
    }
};
