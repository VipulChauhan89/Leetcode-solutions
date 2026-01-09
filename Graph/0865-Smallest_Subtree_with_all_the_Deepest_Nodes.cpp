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
    int maxDepth=0;
    TreeNode *lca=NULL;
    int dfs(TreeNode *root,int depth)
    {
        maxDepth=max(maxDepth,depth);
        if(!root)
        {
            return depth;
        }
        int l=dfs(root->left,depth+1);
        int r=dfs(root->right,depth+1);
        if(l==maxDepth && r==maxDepth)
        {
            lca=root;
        }
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode *root)
    {
        dfs(root,0);
        return lca;
    }
};
