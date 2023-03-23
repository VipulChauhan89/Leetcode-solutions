class Solution {
public:
    void dfs(vector<int> V[],vector<bool> &visited,int u)
    {
        visited[u]=true;
        for(auto i:V[u])
        {
            if(!visited[i])
            {
                dfs(V,visited,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int count=0;
        vector<int> V[n];
        vector<bool> visited(n,false);
        for(auto &i:connections)
        {
            V[i[0]].push_back(i[1]);
            V[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(V,visited,i);
                count++;
            }
        }
        return (n-1>connections.size())?-1:count-1;
    }
};
