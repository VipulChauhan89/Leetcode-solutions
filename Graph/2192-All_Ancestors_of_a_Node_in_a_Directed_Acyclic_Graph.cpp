class Solution {
public:
    void dfs(vector<vector<int>> &graph,int parent,int current,vector<vector<int>> &ans,vector<bool> &visited)
    {
        visited[current]=true;
        for(auto i:graph[current])
        {
            if(!visited[i])
            {
                ans[i].push_back(parent);
                dfs(graph,parent,i,ans,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n,vector<vector<int>> &edges) 
    {
        vector<vector<int>> ans(n),graph(n);
        for(auto &i:edges)
        {
            graph[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++)
        {
            vector<bool> visited(n,false);
            dfs(graph,i,i,ans,visited);
        }
        for(int i=0;i<n;i++)
        {
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
