class Solution {
public:
    void dfs(int node,int cmp,vector<set<int>> &G,vector<int> &visited, unordered_map<int,vector<int>> &mp) 
    {
        visited[node]=1;
        mp[cmp].push_back(node);
        for(auto &i:G[node]) 
        {
            if(!visited[i]) 
            {
                dfs(i,cmp,G,visited,mp);
            }
        }
    }
    int countCompleteComponents(int n,vector<vector<int>> &edges) 
    {
        vector<set<int>> G(n);
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> mp;
        int component=1,ans=0;
        for(auto &i:edges) 
        {
            G[i[0]].insert(i[1]);
            G[i[1]].insert(i[0]);
        }
        for(int i=0;i<n;i++) 
        {
            if(!visited[i]) 
            {
                dfs(i,component++,G,visited,mp);
            }
        }
        for(auto &[cmp,vec]:mp) 
        {
            bool isComplete=true;
            for(int i=0;i<vec.size();i++) 
            {
                for(int j=i+1;j<vec.size();j++) 
                {
                    if(!G[vec[i]].count(vec[j])) 
                    {
                        isComplete=false;
                        break;
                    }
                }
                if(!isComplete)
                {
                    break;
                } 
            }
            if(isComplete)
            {
                ans++;
            } 
        }
        return ans;
    }
};
