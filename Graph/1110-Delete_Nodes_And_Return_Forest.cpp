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
    void dfs(TreeNode *&root,bool flag,vector<TreeNode *> &ans,vector<bool> &set)
    {
        if(root==NULL)
        {
            return;
        }
        dfs(root->left,set[root->val],ans,set);
        dfs(root->right,set[root->val],ans,set);
        if(!set[root->val] && flag)
        {
            ans.push_back(root);
        }
        if(set[root->val])
        {
            root=NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode *root,vector<int> &to_delete) 
    {
        vector<bool> set(1001);
        vector<TreeNode*> ans;
        for(auto i:to_delete)
        {
            set[i]=true;
        }
        dfs(root,true,ans,set);
        return ans;
    }
};
