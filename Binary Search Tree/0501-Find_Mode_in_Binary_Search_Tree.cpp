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
    void inorderTraversal(TreeNode *root, vector<int> &tree)
    {
        if(root==NULL)
        {
            return;
        }
        tree.push_back(root->val);
        inorderTraversal(root->left,tree);
        inorderTraversal(root->right,tree);
    }
    vector<int> findMode(TreeNode *root) 
    {
        vector<int> tree,ans;
        inorderTraversal(root,tree);
        unordered_map<int,int> m;
        int maxFreq=0;
        for(auto i:tree)
        {
            m[i]++;
            maxFreq=max(m[i],maxFreq);
        }
        for(auto &i:m)
        {
            if(i.second==maxFreq)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
