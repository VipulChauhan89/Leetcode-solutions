class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &invoke,vector<int> &vis)
    {
        vis[node]=1;
        for(auto &it:invoke[node])
        {
            if(!vis[it])
            {
                dfs(it,invoke,vis);
            }
        }
    }
    vector<int> remainingMethods(int n,int k,vector<vector<int>> &invocations)
    {
        unordered_map<int,vector<int>> invoke;
        for(auto &it:invocations)
        {
            int u=it[0],v=it[1];
            invoke[u].push_back(v);
        }
        vector<int> vis(n,0);
        dfs(k,invoke,vis);
        vector<int> rem;
        for(auto &it:invocations)
        {
            int u=it[0],v=it[1];
            if(!vis[u] && vis[v])
            {
                for(int i=0;i<n;i++)
                {
                    rem.push_back(i);
                }
                return rem;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                rem.push_back(i);
            }
        }
        return rem;
    }
};
