class Solution {
public:
    void dfs(vector<int> Graph[],vector<bool> &visited,int u)
    {
        visited[u]=true;
        for(auto i:Graph[u])
        {
            if(visited[i]==false)
            {
                dfs(Graph,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected) 
    {
        int n=isConnected.size(),count=0;
        vector<int> Graph[n];
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    Graph[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(Graph,visited,i);
            }
        }
        return count;
    }
};
