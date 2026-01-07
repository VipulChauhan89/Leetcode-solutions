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
    long long dfs(TreeNode *node)
    {
        if(!node)
        {
            return 0;
        }
        node->val+=dfs(node->left)+dfs(node->right);
        return node->val;
    }
    int maxProduct(TreeNode *root)
    {
        long long MOD=1e9+7,ans=0,total=dfs(root);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            if(!node)
            {
                continue;
            }
            long long cur=(total-node->val)*node->val;
            ans=max(ans,cur);
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return ans%MOD;
    }
};
