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
    void findLeaves(TreeNode *node,vector<TreeNode*> trail,vector<TreeNode*> &leaves,unordered_map<TreeNode*,vector<TreeNode*>> &map) 
    {
        if(node==NULL)
        {
            return;
        } 
        vector<TreeNode*> tmp(trail);
        tmp.push_back(node);
        if(!node->left && !node->right) 
        {
            map[node]=tmp;
            leaves.push_back(node);
            return;
        }
        findLeaves(node->left,tmp,leaves,map);
        findLeaves(node->right,tmp,leaves,map);
    }
    int countPairs(TreeNode *root,int distance) 
    {
        unordered_map<TreeNode*,vector<TreeNode*>> map;
        vector<TreeNode*> leaves;
        findLeaves(root,{},leaves,map);
        int ans=0;
        for(int i=0;i<leaves.size();i++) 
        {
            for(int j=i+1;j<leaves.size();j++) 
            {
                vector<TreeNode*> &list_i=map[leaves[i]];
                vector<TreeNode*> &list_j=map[leaves[j]];
                for(int k=0;k<min(list_i.size(),list_j.size());k++) 
                {
                    if(list_i[k]!=list_j[k]) 
                    {
                        int dist=list_i.size()-k+list_j.size()-k;
                        if(dist<=distance)
                        {
                            ans++;
                        } 
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
