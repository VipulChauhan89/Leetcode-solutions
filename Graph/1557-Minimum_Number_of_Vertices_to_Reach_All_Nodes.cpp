class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n,vector<vector<int>> &edges) 
    {
        vector<bool> indegree(n,false);
        vector<int> ans;
        for(auto &e:edges)
        {
            indegree[e[1]]=true;
        }
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
