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
    TreeNode *construct(vector<int> &preorder,vector<int> &postorder,int &index,int l,int h)
    {
        if(index>=preorder.size() || l>h)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[index++]);
        if(l==h)
        {
            return root;
        }
        int i=l;
        while(i<=h && postorder[i]!=preorder[index])
        {
            i++;
        }
        if(i<=h)
        {
            root->left=construct(preorder,postorder,index,l,i);
            root->right=construct(preorder,postorder,index,i+1,h-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int> &preorder,vector<int> &postorder) 
    {
        int index=0;
        return construct(preorder,postorder,index,0,preorder.size()-1);
    }
};
