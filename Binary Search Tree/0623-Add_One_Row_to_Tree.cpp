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
    TreeNode* dfs(TreeNode *node,int h,int depth,int val)
    {
        if(node==NULL)
        {
            return NULL;
        }
        if(h==depth-1)
        {
            TreeNode *l=node->left,*r=node->right;
            node->left=new TreeNode(val);
            node->right=new TreeNode(val);
            node->left->left=l;
            node->right->right=r;
            return node;
        }
        node->left=dfs(node->left,h+1,depth,val);
        node->right=dfs(node->right,h+1,depth,val);
        return node;
    }
    TreeNode* addOneRow(TreeNode *root,int val,int depth) 
    {
        if(depth==1)
        {
            TreeNode *n=new TreeNode(val,root,NULL);
            return n;
        }
        return dfs(root,1,depth,val);
    }
};
