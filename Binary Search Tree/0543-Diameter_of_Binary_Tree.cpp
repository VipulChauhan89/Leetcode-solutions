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
    int diameter(TreeNode *current,int &result)
    {
        if(!current)
        {
            return 0;
        }
        int l=diameter(current->left,result),r=diameter(current->right,result);
        result=max(result,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode *root) 
    {
        int result=0;
        diameter(root,result);
        return result;    
    }
};
