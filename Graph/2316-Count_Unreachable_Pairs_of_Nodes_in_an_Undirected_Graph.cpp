class Solution {
public:
    void dfs(vector<int> V[],vector<bool> &visited,int u,long long &count) 
    {
        visited[u]=true;
        count++;
        for(auto i:V[u]) 
        {
            if(!visited[i]) 
            {
                dfs(V,visited,i,count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int> V[n];
        vector<bool> visited(n,false);
        for(auto &i:edges)
        {
            V[i[0]].push_back(i[1]);
            V[i[1]].push_back(i[0]);
        }
        long long ans=((long long)n*(n-1))/2;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                long long count=0;
                dfs(V,visited,i,count);
                ans-=(count*(count-1))/2;
            }
        }
        return ans;
    }
};
