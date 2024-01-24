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
    void dfs(TreeNode *node, bitset<10> parity,int &ans)
    {
        if(node==NULL)
        {
            return;
        }
        int x=node->val;
        parity[x]=~parity[x];
        if(node->left==NULL && node->right==NULL)
        {
            if(parity.count()<=1)
            {
                ans++;
            }
            return;
        }
        dfs(node->left,parity,ans);
        dfs(node->right,parity,ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        bitset<10> parity=0;
        dfs(root,parity,ans);
        return ans;
    }
};
