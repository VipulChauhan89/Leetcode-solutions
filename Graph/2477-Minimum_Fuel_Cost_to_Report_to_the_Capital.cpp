class Solution {
    public:
        long long minimumFuelCost(vector<vector<int>> &roads,int seats) 
        {
            long long ans=0;
            vector<vector<int>> graph(roads.size()+1);
            for(auto &r:roads) 
            {
                graph[r[0]].push_back(r[1]);
                graph[r[1]].push_back(r[0]);
            }
            dfs(graph,0,-1,seats,ans);
            return ans;
        }
        int dfs(const vector<vector<int>> &graph,int u,int prev,int seats,long long& ans) 
        {
            int people=1;
            for(auto v: graph[u]) 
            {
                if(v == prev)
                {
                    continue;
                }
                people+=dfs(graph,v,u,seats,ans);
            }
            if(u>0)
            {
                ans+=(people+seats-1)/seats;
            }
            return people;
        }
};
