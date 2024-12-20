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
    TreeNode *reverseOddLevels(TreeNode *root) 
    {
        int count=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> node;
            queue<TreeNode*> temp=q;
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
                node.push_back(it->val);
            }
            if(count%2!=0)
            {
                reverse(node.begin(),node.end());
                int i=0;
                while(n--)
                {
                    auto it=temp.front();
                    temp.pop();
                    it->val=node[i];
                    i++;
                }
            }
            count++;
        }
        return root;
    }
};
