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
    string s;
    int index=0,level=0;
    void solve(TreeNode *root,int depth)
    {
        while(index<s.length() && depth==level)
        {
            int num=0;
            while(index<s.length() && isdigit(s[index]))
            {
                num=num*10+(s[index++]-'0');
            }
            TreeNode *node=new TreeNode(num);
            if(!root->left)
            {
                root->left=node;
            }
            else
            {
                root->right=node;
            }
            level=0;
            while(index<s.length() && s[index]=='-')
            {
                level++;
                index++;
            }
            solve(node,depth+1);
        }
    }
    TreeNode* recoverFromPreorder(string traversal) 
    {
        s=traversal;
        TreeNode *node=new TreeNode(-1);
        solve(node,0);
        return node->left;
    }
};
