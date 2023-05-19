class Solution {
public:
    bool dfs(vector<int>G[],vector<int> &visited,int u,int x)
    {
        if(visited[u]!=-1)
        {
            return (visited[u]!=x)?false:true;
        }
        visited[u]=x;
        bool ans=true;
        for(auto &i:G[u])
        {
            ans&=dfs(G,visited,i,x^1);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>> &graph) 
    {
        bool ans=true;
        int n=graph.size();
        vector<int> G[n],visited(n,-1);
        for(int i=0;i<n;i++)
        {
            for(auto e:graph[i])
            {
                G[i].push_back(e);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                ans&=dfs(G,visited,i,0);
            }
        }
        return ans;
    }
};
