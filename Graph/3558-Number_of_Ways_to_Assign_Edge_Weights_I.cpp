class Solution {
public:
    static const int MOD=1e9+7;
    int dfs(vector<vector<int>> &adj,int node,int par)
    {
        int depth=0;
        for(auto &child:adj[node])
        {
            if(child==par)
            {
                continue;
            }
            depth=max(depth,1+dfs(adj,child,node));
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto &e:edges)
        {
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int depth=dfs(adj,1,-1);
        long long ans=1;
        for(int i=1;i<depth;i++)
        {
            ans=(ans*2)%MOD;
        }
        return ans;
    }
};
