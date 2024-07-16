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
    bool dfs(TreeNode * root,int x,string &path)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==x)
        {
            return true;
        }
        path.push_back('L');
        if(dfs(root->left,x,path))
        {
            return true; 
        }
        path.pop_back();
        path.push_back('R');
        if(dfs(root->right,x,path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode *root,int startValue,int destValue) 
    {
        string pathFrom,pathTo;
        dfs(root,startValue,pathFrom);
        dfs(root,destValue,pathTo);
        int n=pathFrom.size(),m=pathTo.size(),size=0;
        int mn=min(n,m);
        while(size<mn && pathFrom[size]==pathTo[size])
        {
            size++;
        }
        return string(n-size,'U')+string(pathTo.begin()+size,pathTo.end());
    }
};
