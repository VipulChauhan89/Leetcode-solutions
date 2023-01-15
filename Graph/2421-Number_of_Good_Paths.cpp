class Solution {
public:
    vector<map<int, int>> m;
    vector<vector<int>> graph;
    vector<bool> visited;
    int numberOfGoodPaths(vector<int> &vals,vector<vector<int>> &edges) 
    {
        int n=vals.size(),ans=0;
        m.resize(n);
        graph.resize(n);
        visited.resize(n,false);
        for (auto &e: edges) 
        {
            int u=e[0],v=e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(ans,0,vals);
        return ans+n;
    }
    void dfs(int &count,int u,vector<int>& vals) 
    {
        visited[u]=true;
        for(auto &v:graph[u]) 
        {
            int cnt=0;
            if(visited[v]==true)
            {
                continue;
            }
            dfs(cnt,v,vals);
            count+=cnt;
            auto it=m[v].lower_bound(vals[u]);
            m[v].erase(m[v].begin(), it);
            if (m[u].size()<m[v].size()) 
            {
                swap(m[u],m[v]);    
            }
            for(auto &it:m[v]) 
            {
                count+=m[u][it.first]*it.second; 
                m[u][it.first]+=it.second;
            }
        }
        count+=m[u][vals[u]];
        ++m[u][vals[u]]; 
    }
};
