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
    
    pair<int,int> inOrder(TreeNode *node,int &count)
    {
        if(node==NULL)
        {
            return {0,0};
        } 
        auto [sumL,iL]=inOrder(node->left,count);
        int sum=node->val,i=1;
        auto [sumR,iR]=inOrder(node->right,count);
        sum+=(sumL+sumR);
        i+=(iL+iR);
        if(sum/i==node->val)
        {
            count++;
        } 
        return {sum,i};
    }
    int averageOfSubtree(TreeNode *root) 
    {
        int count=0;
        inOrder(root,count);
        return count;
    }
};
