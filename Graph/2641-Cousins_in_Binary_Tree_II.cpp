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
    void dfs(vector<TreeNode *> root)
    {
        if(!root.empty())
        {
            int sum=0;
            for(auto i:root)
            {
                if(!i)
                {
                    continue;
                }
                if(i->left)
                {
                    sum+=i->left->val;
                }
                if(i->right)
                {
                    sum+=i->right->val;
                }
            }
            vector<TreeNode *> child;
            for(auto i:root)
            {
                int currentSum=0;
                if(i->left)
                {
                    currentSum+=i->left->val;
                }
                if(i->right)
                {
                    currentSum+=i->right->val;
                }
                if(i->left)
                {
                    i->left->val=sum-currentSum;
                    child.push_back(i->left);
                }
                if(i->right)
                {
                    i->right->val=sum-currentSum;
                    child.push_back(i->right);
                }
            }
            dfs(child);
        }
    }
    TreeNode* replaceValueInTree(TreeNode *root) 
    {
        root->val=0;
        dfs(vector<TreeNode*>{root});
        return root;
    }
};
