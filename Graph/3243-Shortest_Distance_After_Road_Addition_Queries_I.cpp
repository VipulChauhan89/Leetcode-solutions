class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>> &queries) 
    {
        vector<int> ans,dist(n);
        vector<vector<int>> adj(n);
        iota(dist.begin(),dist.end(),0);
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
        }
        for(auto &i:queries)
        {
            int src=i[0],des=i[1];
            adj[src].push_back(des);
            if(dist[src]+1<dist[des])
            {
                queue<int> q;
                q.push(des);
                dist[des]=dist[src]+1;
                while(q.size())
                {
                    int index=q.front();
                    q.pop();
                    for(auto j:adj[index])
                    {
                        if(dist[index]+1<dist[j])
                        {
                            dist[j]=dist[index]+1;
                            q.push(j);
                        }
                    }
                }
            }
            ans.emplace_back(dist.back());
        }
        return ans;
    }
};
