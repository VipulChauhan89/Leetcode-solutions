class Solution {
public:
    void dfs(vector<int> A[],int u,vector<bool> &visited)
    {
        visited[u]=true;
        for(auto it=A[u].begin();it!=A[u].end();it++)
        {
            if(visited[*it]==false)
            {
                dfs(A,*it,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> A[n];
        for(int i=0;i<edges.size();i++)
        {
            A[edges[i][0]].push_back(edges[i][1]);
            A[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        dfs(A,source,visited);
        return visited[destination];
    }
};
