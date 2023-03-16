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
    TreeNode* create(vector<int> &inorder,vector<int> &postorder,int is,int ie,int ps,int pe)
    {
        if(ps>pe)
        {
            return NULL;
        }
        TreeNode *node=new TreeNode(postorder[pe]);
        int pos;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==node->val)
            {
                pos=i;
                break;
            }
        }
        node->left=create(inorder,postorder,is,pos-1,ps,ps+pos-is-1);
        node->right=create(inorder,postorder,pos+1,ie,pe-ie+pos,pe-1);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder,vector<int> &postorder) 
    {
        return create(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
