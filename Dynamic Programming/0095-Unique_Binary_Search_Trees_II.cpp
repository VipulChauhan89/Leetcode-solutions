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
    map<pair<int,int>,vector<TreeNode*>>m;
    vector<TreeNode*> solve(int start,int end)
    {
        vector<TreeNode*>v;
        if(start>end)
        {
            v.push_back(NULL);
            return v;
        }
        if(start==end)
        {
            v.push_back(new TreeNode(start));
            return v;
        }
        if(m.count({start,end}))
        {
            return m[{start,end}];
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>l=solve(start,i-1);
            vector<TreeNode*>r=solve(i+1,end);
            for(TreeNode* x:l)
            {
                for(TreeNode* x1:r)
                {
                    TreeNode*root=new TreeNode(i);
                    root->left=x;
                    root->right=x1;
                    v.push_back(root);
                }
            }
        }
        return m[{start,end}]=v;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        return solve(1,n);
    }
};
