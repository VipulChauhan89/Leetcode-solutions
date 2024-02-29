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
    bool isEvenOddTree(TreeNode *root) 
    {
        if(root==NULL)
        {
            return true;
        }
        queue<TreeNode *> q;
        int level=0;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size(),prev=(level%2==0)?numeric_limits<int>::min():numeric_limits<int>::max();
            for(int i=0;i<s;i++)
            {
                TreeNode *n=q.front();
                q.pop();
                if((level%2==0 && (n->val%2==0 || n->val<=prev)) || (level%2==1 && (n->val%2==1 || n->val>=prev))) 
                {
                    return false;
                }
                prev=n->val;
                if(n->left)
                {
                    q.push(n->left);
                }
                if(n->right)
                {
                    q.push(n->right);
                }
            }
            level++;
        }
        return true;
    }
};
