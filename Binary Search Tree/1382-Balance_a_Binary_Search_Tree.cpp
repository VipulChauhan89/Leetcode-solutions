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
    void inorder(TreeNode *root,vector<int> &a)
    {
        if(root!=NULL)
        {
            inorder(root->left,a);
            a.push_back(root->val);
            inorder(root->right,a);
        }
    }
    TreeNode * buildTree(int s,int e,vector<int> &a)
    {
        if(s>e)
        {
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode *root=new TreeNode(a[mid]);
        root->left=buildTree(s,mid-1,a);
        root->right=buildTree(mid+1,e,a);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root) 
    {
        vector<int> a;
        inorder(root,a);
        return buildTree(0,a.size()-1,a);
    }
};
