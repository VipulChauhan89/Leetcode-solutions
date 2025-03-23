class Solution {
public:
    int countPaths(int n,vector<vector<int>> &roads) 
    {
        int mod=1e9+7;
        vector<vector<pair<int,int>>> G(n);
        vector<long long> distance(n,LLONG_MAX),count(n,0);
        distance[0]=0;
        count[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> p;
        p.push({0,0});
        for(auto &i:roads)
        {
            int u=i[0],v=i[1],time=i[2];
            G[u].push_back({v,time});
            G[v].push_back({u,time});
        }
        while(!p.empty())
        {
            auto [curr,u]=p.top();
            p.pop();
            if(curr>distance[u])
            {
                continue;
            }
            for(auto &i:G[u])
            {
                int v=i.first,time=i.second;
                long long new_path=curr+time;
                if(new_path<distance[v])
                {
                    distance[v]=new_path;
                    count[v]=count[u];
                    p.push({new_path,v});
                }
                else if(new_path==distance[v])
                {
                    count[v]=(count[v]+count[u])%mod;
                }
            }
        }
        return count[n-1];
    }
};
