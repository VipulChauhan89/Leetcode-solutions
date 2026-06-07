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
    TreeNode* createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int,TreeNode*> node;
        node.reserve(descriptions.size()+1);
        int root=0;
        for(auto &i:descriptions)
        {
            int x=i[0],y=i[1],isLeft=i[2];
            if(!node.contains(x))
            {
                node[x]=new TreeNode(x);
                root^=x;
            }
            if(!node.contains(y))
            {
                node[y]=new TreeNode(y);
                root^=y;
            }
            if(isLeft)
            {
                node[x]->left=node[y];
            }
            else
            {
                node[x]->right=node[y];
            }
            root^=y;
        }
        return node[root];
    }
};
