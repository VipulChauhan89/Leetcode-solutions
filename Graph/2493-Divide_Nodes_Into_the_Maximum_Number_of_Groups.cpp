class Solution {
public:
    int magnificentSets(int n,vector<vector<int>> &edges) 
    {
        vector<vector<int>> graph(n);
        vector<int> distance(n);
        for(auto &i:edges)
        {
            int u=i[0]-1,v=i[1]-1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            int mxDis=1,root=i;
            queue<int> q{{i}};
            vector<int> dis(n);
            dis[i]=1;
            while(!q.empty())
            {
                int current=q.front();
                q.pop();
                root=min(root,current);
                for(auto j:graph[current])
                {
                    if(dis[j]==0)
                    {
                        dis[j]=dis[current]+1;
                        mxDis=max(mxDis,dis[j]);
                        q.push(j);
                    }
                    else if(abs(dis[j]-dis[current])!=1)
                    {
                        return -1;
                    }
                }
            }
            distance[root]=max(distance[root],mxDis);
        }
        return accumulate(distance.begin(),distance.end(),0);
    }
};
