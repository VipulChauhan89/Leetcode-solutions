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
    void leafNodes(TreeNode *r,vector<int> &v)
    {
        if(r==NULL)
        {
            return;
        }
        else if(r->left==r->right)
        {
            v.push_back(r->val);
            return;
        }
        leafNodes(r->left,v);
        leafNodes(r->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> r1,r2;
        leafNodes(root1,r1);
        leafNodes(root2,r2);
        return r1==r2;
    }
};
