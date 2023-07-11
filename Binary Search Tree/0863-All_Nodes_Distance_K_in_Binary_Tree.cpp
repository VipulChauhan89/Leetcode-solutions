/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> m;
    unordered_map<TreeNode*,bool> visited;
    void dfs(TreeNode* root,TreeNode *parent)
    {
        if(root==NULL)
        {
            return;
        } 
        m[root]=parent;
        dfs(root->left,root);
        dfs(root->right,root);
        return;
    }

    vector<int> findNodes(TreeNode* origin,int distance)
    {
        if(origin==NULL || visited[origin]==true)
        {
            return vector<int>();
        }
        if(distance==0)
        {
            return vector<int>(1,origin->val);
        }
        visited[origin]=true;
        vector<int> res1=findNodes(origin->left,distance-1);
        vector<int> res2=findNodes(origin->right,distance-1);
        vector<int> res3=findNodes(m[origin],distance-1);
        res1.insert(res1.end(),res2.begin(),res2.end());
        res1.insert(res1.end(),res3.begin(),res3.end());
        return res1;
    }

    vector<int> distanceK(TreeNode* root,TreeNode* target,int k) 
    {
        dfs(root,NULL);
        return findNodes(target,k);
    }
};
