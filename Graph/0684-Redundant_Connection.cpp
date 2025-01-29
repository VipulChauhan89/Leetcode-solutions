class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<bool> &visited,int u,int v) 
    {
        if(u==v)
        {
            return true;
        } 
        visited[u]=true;
        for(int &i:graph[u]) 
        {
            if(!visited[i] && dfs(graph,visited,i,v)) 
            {
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        for(auto &i:edges) 
        {
            int u=i[0],v=i[1];
            vector<bool> visited(n+1,false);
            if(dfs(graph,visited,u,v)) 
            {
                return i;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};
