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
    int maxLevelSum(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level=1,maxLevel=1,maxSum=INT_MIN;
        while(!q.empty())
        {
            int size=q.size(),levelSum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                levelSum+=node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(levelSum>maxSum)
            {
                maxSum=levelSum;
                maxLevel=level;
            }
            level++;
        }
        return maxLevel;
    }
};
